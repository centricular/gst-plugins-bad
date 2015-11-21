mpegts_sources = [
  'gstmpegtssection.c',
  'gstmpegtsdescriptor.c',
  'gst-dvb-descriptor.c',
  'gst-dvb-section.c',
  'gst-atsc-section.c',
]

mpegts_headers = [
  'gstmpegtssection.h',
  'gst-atsc-section.h',
  'gst-dvb-section.h',
  'gst-scte-section.h',
  'gstmpegtsdescriptor.h',
  'gst-dvb-descriptor.h',
]

mkenums = find_program('mpegts_enum.py')

mpegts_h = custom_target('mpegtsenum_h',
  output : 'gstmpegts-enumtypes.h',
  input : mpegts_headers,
  command : [mkenums, '@OUTPUT@', '@INPUT@'])

mpegts_c = custom_target('mpegtsenum_c',
  output : 'gstmpegts-enumtypes.c',
  input : mpegts_headers,
  command : [mkenums, '@OUTPUT@', '@INPUT@'])

gst = library('gstmpegts-' + api_version,
  mpegts_sources, mpegts_h, mpegts_c,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
