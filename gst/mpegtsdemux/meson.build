tsdemux_sources = [
  'mpegtspacketizer.c',
  'mpegtsbase.c',
  'mpegtsparse.c',
  'tsdemux.c',
  'gsttsdemux.c',
  'pesparse.c',
]

gstmpegtsdemux = library('gstmpegtsdemux',
  tsdemux_sources,
  c_args : core_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : core_incs,
  link_with : gstcodecparsers,
  dependencies : [ gstmpegts_dep, gsttag_dep, gstpbutils_dep, gstbase_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
