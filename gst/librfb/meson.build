rfbsrc_sources = [
  'gstrfbsrc.c',
  'rfbbuffer.c',
  'rfbdecoder.c',
  'd3des.c',
]

gstrfbsrc = library('gstrfbsrc',
  rfbsrc_sources,
  c_args : core_args,
  include_directories : [ core_incs, include_directories('..') ],
  dependencies : [ gstbase_dep, gstvideo_dep, gio_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
