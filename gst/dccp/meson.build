dccp_sources = [
  'gstdccpplugin.c',
  'gstdccp.c',
  'gstdccpserversink.c',
  'gstdccpserversrc.c',
  'gstdccpclientsink.c',
  'gstdccpclientsrc.c',
]

gstdccp = library('gstdccp',
  dccp_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
