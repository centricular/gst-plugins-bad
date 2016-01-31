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
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep],
  install : true,
  install_dir : plugins_install_dir,
)
