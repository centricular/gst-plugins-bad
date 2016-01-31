sdp_sources = [
  'gstsdpelem.c',
  'gstsdpdemux.h',
  'gstsdpdemux.c'
]

gstsdpelem = library('gstspdelem',
  sdp_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstrtp_dep, gstsdp_dep],
  install : true,
  install_dir : plugins_install_dir,
)
