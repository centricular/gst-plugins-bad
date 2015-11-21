subdir('tsmux')

tsmux_sources = [
  'mpegtsmux.c',
  'mpegtsmux_aac.c',
  'mpegtsmux_ttxt.c',
]

gstmptedtsmux = library('gstmpegtsmux',
  tsmux_sources,
  c_args : core_args,
  include_directories : core_incs,
  link_with : tsmux,
  dependencies : [gstbase_dep, gstvideo_dep],
)
