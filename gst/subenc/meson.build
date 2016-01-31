subenc_sources = [
  'gstsrtenc.c',
  'gstsubenc.c',
  'gstwebvttenc.c',
]

gstsubenc = library('gstsubenc',
  subenc_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep],
  install : true,
  install_dir : plugins_install_dir,
)
