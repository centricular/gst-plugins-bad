psmux_sources = [
  'mpegpsmux.c',
  'psmux.c',
  'psmuxstream.c',
  'mpegpsmux_aac.c',
  'mpegpsmux_h264.c',
]

gstmpegpsmux = library('gstmpegpsmux',
  psmux_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
