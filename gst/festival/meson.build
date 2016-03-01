festival_sources = [
  'gstfestival.c'
]

gstfestival = library('gstfestival',
  festival_sources,
  c_args : gst_plugins_bad_args,
  link_args : winsock2_link_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
  install : true,
  install_dir : plugins_install_dir,
)
