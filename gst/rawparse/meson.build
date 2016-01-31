raw_sources = [
  'gstrawparse.c',
  'gstaudioparse.c',
  'gstvideoparse.c',
  'plugin.c',
]

gstrawparse = library('gstrawparse',
  raw_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstvideo_dep, gstaudio_dep],
  install : true,
  install_dir : plugins_install_dir,
)
