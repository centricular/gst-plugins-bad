tsmux_sources = [
  'mpegtsmux.c',
  'mpegtsmux_aac.c',
  'mpegtsmux_opus.c',
  'mpegtsmux_ttxt.c',
  'tsmux/tsmux.c',
  'tsmux/tsmuxstream.c',
]

gstmpegtsmux = library('gstmpegtsmux',
  tsmux_sources,
  c_args : core_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : core_incs,
  dependencies : [ gstmpegts_dep, gstpbutils_dep, gstaudio_dep, gstvideo_dep, gstbase_dep ],
)
