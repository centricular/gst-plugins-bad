/* 
 * Copyright (C) 2012 Collabora Ltd.
 *     Author: Sebastian Dröge <sebastian.droege@collabora.co.uk>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 *
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "gstmfcdec.h"

#include <string.h>

GST_DEBUG_CATEGORY_STATIC (gst_mfc_dec_debug);
#define GST_CAT_DEFAULT gst_mfc_dec_debug

static gboolean gst_mfc_dec_start (GstVideoDecoder * decoder);
static gboolean gst_mfc_dec_stop (GstVideoDecoder * decoder);
static gboolean gst_mfc_dec_set_format (GstVideoDecoder * decoder,
    GstVideoCodecState * state);
static gboolean gst_mfc_dec_reset (GstVideoDecoder * decoder, gboolean hard);
static gboolean gst_mfc_dec_finish (GstVideoDecoder * decoder);
static GstFlowReturn gst_mfc_dec_handle_frame (GstVideoDecoder * decoder,
    GstVideoCodecFrame * frame);

static GstStaticPadTemplate gst_mfc_dec_sink_template =
GST_STATIC_PAD_TEMPLATE ("sink",
    GST_PAD_SINK,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS ("video/x-h264, "
        "parsed = (boolean) true, "
        "stream-format = (string) byte-stream, " "alignment = (string) au")
    );

static GstStaticPadTemplate gst_mfc_dec_src_template =
GST_STATIC_PAD_TEMPLATE ("src",
    GST_PAD_SRC,
    GST_PAD_ALWAYS,
    GST_STATIC_CAPS (GST_VIDEO_CAPS_YUV ("NV12"))
    );

GST_BOILERPLATE (GstMFCDec, gst_mfc_dec, GstVideoDecoder,
    GST_TYPE_VIDEO_DECODER);

static void
gst_mfc_dec_base_init (gpointer g_class)
{
  GstElementClass *element_class = (GstElementClass *) g_class;

  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&gst_mfc_dec_src_template));
  gst_element_class_add_pad_template (element_class,
      gst_static_pad_template_get (&gst_mfc_dec_sink_template));

  gst_element_class_set_details_simple (element_class,
      "Samsung Exynos MFC decoder",
      "Codec/Decoder/Video",
      "Decode video streams via Samsung Exynos",
      "Sebastian Dröge <sebastian.droege@collabora.co.uk>");
}

static void
gst_mfc_dec_class_init (GstMFCDecClass * klass)
{
  GstVideoDecoderClass *video_decoder_class;

  video_decoder_class = (GstVideoDecoderClass *) klass;

  mfc_dec_init_debug ();

  video_decoder_class->start = GST_DEBUG_FUNCPTR (gst_mfc_dec_start);
  video_decoder_class->stop = GST_DEBUG_FUNCPTR (gst_mfc_dec_stop);
  video_decoder_class->finish = GST_DEBUG_FUNCPTR (gst_mfc_dec_finish);
  video_decoder_class->reset = GST_DEBUG_FUNCPTR (gst_mfc_dec_reset);
  video_decoder_class->set_format = GST_DEBUG_FUNCPTR (gst_mfc_dec_set_format);
  video_decoder_class->handle_frame =
      GST_DEBUG_FUNCPTR (gst_mfc_dec_handle_frame);

  GST_DEBUG_CATEGORY_INIT (gst_mfc_dec_debug, "mfcdec", 0,
      "Samsung Exynos MFC Decoder");
}

static void
gst_mfc_dec_init (GstMFCDec * self, GstMFCDecClass * klass)
{
  GstVideoDecoder *decoder = (GstVideoDecoder *) self;

  gst_video_decoder_set_packetized (decoder, TRUE);
}

static gboolean
gst_mfc_dec_start (GstVideoDecoder * decoder)
{
  GstMFCDec *self = GST_MFC_DEC (decoder);

  GST_DEBUG_OBJECT (self, "Starting");

  /* Initialize with H264 here, we chose the correct codec in set_format */
  self->context = mfc_dec_create (CODEC_TYPE_H264, 1);
  if (!self->context) {
    GST_ELEMENT_ERROR (self, LIBRARY, INIT,
        ("Failed to initialize MFC decoder context"), (NULL));
  }

  return self->context != NULL;
}

static gboolean
gst_mfc_dec_stop (GstVideoDecoder * video_decoder)
{
  GstMFCDec *self = GST_MFC_DEC (video_decoder);

  GST_DEBUG_OBJECT (self, "Stopping");

  if (self->input_state) {
    gst_video_codec_state_unref (self->input_state);
    self->input_state = NULL;
  }

  if (self->context) {
    mfc_dec_destroy (self->context);
    self->context = NULL;
  }
  self->initialized = FALSE;

  GST_DEBUG_OBJECT (self, "Stopped");

  return TRUE;
}

static gboolean
gst_mfc_dec_set_format (GstVideoDecoder * decoder, GstVideoCodecState * state)
{
  GstMFCDec *self = GST_MFC_DEC (decoder);
  GstStructure *s;
  gint ret;

  GST_DEBUG_OBJECT (self, "Setting format: %" GST_PTR_FORMAT, state->caps);

  s = gst_caps_get_structure (state->caps, 0);

  if (gst_structure_has_name (s, "video/x-h264")) {
    if ((ret = mfc_dec_set_codec (self->context, CODEC_TYPE_H264)) < 0) {
      GST_ELEMENT_ERROR (self, LIBRARY, SETTINGS,
          ("Failed to set codec to H264"), (NULL));
      return FALSE;
    }
  } else {
    g_return_val_if_reached (FALSE);
  }

  if (self->input_state)
    gst_video_codec_state_unref (self->input_state);
  self->input_state = gst_video_codec_state_ref (state);

  return TRUE;
}

static gboolean
gst_mfc_dec_reset (GstVideoDecoder * decoder, gboolean hard)
{
  GstMFCDec *self = GST_MFC_DEC (decoder);

  GST_DEBUG_OBJECT (self, "Resetting");
  if (self->context)
    mfc_dec_flush (self->context);

  return TRUE;
}

static GstFlowReturn
gst_mfc_dec_queue_input (GstMFCDec * self, GstBuffer * inbuf)
{
  GstFlowReturn ret = GST_FLOW_OK;
  gint mfc_ret;
  struct mfc_buffer *mfc_inbuf = NULL;
  guint8 *mfc_inbuf_data;
  gint mfc_inbuf_size;
  const guint8 *inbuf_data;
  gsize inbuf_size;

  GST_DEBUG_OBJECT (self, "Dequeueing input");

  if ((mfc_ret = mfc_dec_dequeue_input (self->context, &mfc_inbuf)) < 0) {
    if (mfc_ret == -2) {
      GST_DEBUG_OBJECT (self, "Timeout dequeueing input, trying again");
      mfc_ret = mfc_dec_dequeue_input (self->context, &mfc_inbuf);
    }

    if (mfc_ret < 0)
      goto dequeue_error;
  }

  g_assert (mfc_inbuf != NULL);

  if (inbuf) {
    inbuf_data = GST_BUFFER_DATA (inbuf);
    inbuf_size = GST_BUFFER_SIZE (inbuf);

    mfc_inbuf_data = mfc_buffer_get_input_data (mfc_inbuf);
    g_assert (mfc_inbuf_data != NULL);
    mfc_inbuf_size = mfc_buffer_get_input_max_size (mfc_inbuf);

    GST_DEBUG_OBJECT (self, "Have input buffer %p with size %d", mfc_inbuf_data,
        mfc_inbuf_size);

    if (mfc_inbuf_size < inbuf_size)
      goto too_small_inbuf;

    memcpy (mfc_inbuf_data, inbuf_data, inbuf_size);
    mfc_buffer_set_input_size (mfc_inbuf, inbuf_size);
  } else {
    GST_DEBUG_OBJECT (self, "Passing EOS input buffer");

    mfc_buffer_set_input_size (mfc_inbuf, 0);
  }

  if ((mfc_ret = mfc_dec_enqueue_input (self->context, mfc_inbuf)) < 0)
    goto enqueue_error;

done:
  return ret;

dequeue_error:
  {
    GST_ELEMENT_ERROR (self, LIBRARY, FAILED,
        ("Failed to dequeue input buffer"), ("mfc_dec_dequeue_input: %d",
            mfc_ret));
    ret = GST_FLOW_ERROR;
    goto done;
  }

too_small_inbuf:
  {
    GST_ELEMENT_ERROR (self, STREAM, FORMAT, ("Too large input frames"),
        ("Maximum size %d, got %d", mfc_inbuf_size, inbuf_size));
    ret = GST_FLOW_ERROR;
    goto done;
  }

enqueue_error:
  {
    GST_ELEMENT_ERROR (self, LIBRARY, FAILED,
        ("Failed to enqueue input buffer"), ("mfc_dec_enqueue_input: %d",
            mfc_ret));
    ret = GST_FLOW_ERROR;
    goto done;
  }
}

static GstVideoCodecFrame *
gst_mfc_dec_get_earliest_frame (GstMFCDec * self)
{
  GstVideoCodecFrame *frame = NULL;
  GList *frames, *l;

  frames = gst_video_decoder_get_frames (GST_VIDEO_DECODER (self));

  for (l = frames; l; l = l->next) {
    GstVideoCodecFrame *tmp = l->data;

    if (!frame) {
      frame = tmp;
    } else if (frame->pts > tmp->pts) {
      gst_video_codec_frame_unref (frame);
      frame = tmp;
    } else {
      gst_video_codec_frame_unref (tmp);
    }
  }

  g_list_free (frames);

  return frame;
}

static GstFlowReturn
gst_mfc_dec_dequeue_output (GstMFCDec * self)
{
  GstFlowReturn ret = GST_FLOW_OK;
  gint mfc_ret;
  GstVideoCodecFrame *frame = NULL;
  GstBuffer *outbuf = NULL;
  struct mfc_buffer *mfc_outbuf = NULL;
  gint width, height;
  gint crop_left, crop_top, crop_width, crop_height;
  GstVideoCodecState *state = NULL;
  gint64 deadline;

  GST_DEBUG_OBJECT (self, "Dequeueing output");

  if (!self->initialized) {
    if ((mfc_ret = mfc_dec_init (self->context, 1)) < 0)
      goto initialize_error;
    self->initialized = TRUE;
  }

  if ((mfc_ret = mfc_dec_output_available (self->context)) == 0)
    return GST_FLOW_OK;
  else if (mfc_ret < 0)
    goto output_available_error;

  mfc_dec_get_output_size (self->context, &width, &height);
  mfc_dec_get_crop_size (self->context, &crop_left, &crop_top, &crop_width,
      &crop_height);

  GST_DEBUG_OBJECT (self, "Have output buffer: width %d, height %d, "
      "crop_left %d, crop_right %d, "
      "crop_width %d, crop_height %d", width, height,
      crop_left, crop_top, crop_width, crop_height);

  state = gst_video_decoder_get_output_state (GST_VIDEO_DECODER (self));
  if (!state || state->info.width != crop_width
      || state->info.height != crop_height) {
    GST_DEBUG_OBJECT (self, "Creating new output state");

    if (state)
      gst_video_codec_state_unref (state);
    state =
        gst_video_decoder_set_output_state (GST_VIDEO_DECODER (self),
        GST_VIDEO_FORMAT_NV12, crop_width, crop_height, self->input_state);
  }

  if ((mfc_ret = mfc_dec_dequeue_output (self->context, &mfc_outbuf)) < 0) {
    if (mfc_ret == -2) {
      GST_DEBUG_OBJECT (self, "Timeout dequeueing output, trying again");
      mfc_ret = mfc_dec_dequeue_output (self->context, &mfc_outbuf);
    }

    if (mfc_ret < 0)
      goto dequeue_error;
  }

  g_assert (mfc_outbuf != NULL);

  /* FIXME: Replace this by gst_video_decoder_get_frame() with an ID */
  frame = gst_mfc_dec_get_earliest_frame (self);

  if (frame) {
    deadline =
        gst_video_decoder_get_max_decode_time (GST_VIDEO_DECODER (self), frame);
    if (deadline < 0) {
      GST_LOG_OBJECT (self,
          "Dropping too late frame: deadline %" G_GINT64_FORMAT, deadline);
      ret = gst_video_decoder_drop_frame (GST_VIDEO_DECODER (self), frame);
      goto done;

    }
    ret =
        gst_video_decoder_alloc_output_frame (GST_VIDEO_DECODER (self), frame);

    if (ret != GST_FLOW_OK)
      goto alloc_error;

    outbuf = frame->output_buffer;
  } else {
    outbuf = gst_video_decoder_alloc_output_buffer (GST_VIDEO_DECODER (self));

    if (!outbuf) {
      ret = GST_FLOW_ERROR;
      goto alloc_error;
    }
  }

  /* TODO: Here now copy the mfc_outbuf to outbuf using the FIMC detiler */

  if (frame) {
    ret = gst_video_decoder_finish_frame (GST_VIDEO_DECODER (self), frame);
    frame = NULL;
  } else {
    ret = gst_pad_push (GST_VIDEO_DECODER_SRC_PAD (self), outbuf);
  }

  if (ret != GST_FLOW_OK)
    GST_INFO_OBJECT (self, "Pushing frame returned: %s",
        gst_flow_get_name (ret));

done:
  if (mfc_outbuf) {
    if ((mfc_ret = mfc_dec_enqueue_output (self->context, mfc_outbuf)) < 0)
      goto enqueue_error;
  }

  if (state)
    gst_video_codec_state_unref (state);
  if (frame)
    gst_video_codec_frame_unref (frame);

  return ret;

initialize_error:
  {
    GST_ELEMENT_ERROR (self, LIBRARY, INIT, ("Failed to initialize output"),
        ("mfc_dec_init: %d", mfc_ret));
    ret = GST_FLOW_ERROR;
    goto done;
  }

output_available_error:
  {
    GST_ELEMENT_ERROR (self, LIBRARY, FAILED,
        ("Failed to check if output is available"),
        ("mfc_dec_output_available: %d", mfc_ret));
    ret = GST_FLOW_ERROR;
    goto done;
  }

dequeue_error:
  {
    GST_ELEMENT_ERROR (self, LIBRARY, FAILED,
        ("Failed to dequeue output buffer"), ("mfc_dec_dequeue_output: %d",
            mfc_ret));
    ret = GST_FLOW_ERROR;
    goto done;
  }

alloc_error:
  {
    GST_ELEMENT_ERROR (self, CORE, FAILED, ("Failed to allocate output buffer"),
        (NULL));
    ret = GST_FLOW_ERROR;
    goto done;
  }

enqueue_error:
  {
    GST_ELEMENT_ERROR (self, LIBRARY, FAILED,
        ("Failed to enqueue output buffer"), ("mfc_dec_enqueue_output: %d",
            mfc_ret));
    ret = GST_FLOW_ERROR;
    goto done;
  }
}

static GstFlowReturn
gst_mfc_dec_finish (GstVideoDecoder * decoder)
{
  GstMFCDec *self = GST_MFC_DEC (decoder);
  GstFlowReturn ret;

  GST_DEBUG_OBJECT (self, "Finishing decoding");

  if ((ret = gst_mfc_dec_queue_input (self, NULL)) != GST_FLOW_OK)
    return ret;

  return gst_mfc_dec_dequeue_output (self);
}

static GstFlowReturn
gst_mfc_dec_handle_frame (GstVideoDecoder * decoder, GstVideoCodecFrame * frame)
{
  GstMFCDec *self = GST_MFC_DEC (decoder);
  GstFlowReturn ret = GST_FLOW_OK;

  GST_DEBUG_OBJECT (self, "Handling frame");

  /* FIXME: Would be good to assign an ID to input frames */
  if (frame->pts == GST_CLOCK_TIME_NONE) {
    GST_ERROR_OBJECT (self, "Only PTS timestamped streams supported so far");
    gst_video_codec_frame_unref (frame);
    return GST_FLOW_ERROR;
  }

  if ((ret =
          gst_mfc_dec_queue_input (self, frame->input_buffer)) != GST_FLOW_OK) {
    gst_video_codec_frame_unref (frame);
    return ret;
  }

  gst_video_codec_frame_unref (frame);

  return gst_mfc_dec_dequeue_output (self);
}
