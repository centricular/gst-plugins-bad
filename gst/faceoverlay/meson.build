fover_sources = [
  'gstfaceoverlay.c',
]

gstfaceoverlay = library('gstfaceoverlay',
  fover_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
  install : true,
  install_dir : plugins_install_dir,
)
