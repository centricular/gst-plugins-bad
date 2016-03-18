rfbsrc_sources = [
  'gstrfbsrc.c',
  'rfbbuffer.c',
  'rfbdecoder.c',
  'd3des.c',
]

gstrfbsrc = library('gstrfbsrc',
  rfbsrc_sources,
  c_args : gst_plugins_bad_args,
  include_directories : [ gst_plugins_bad_incs, include_directories('..') ],
  dependencies : [gstbase_dep, gstvideo_dep, gio_dep, x11_dep],
  install : true,
  install_dir : plugins_install_dir,
)
