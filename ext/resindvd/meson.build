resindvd_sources = [
  'gstmpegdemux.c',
  'gstmpegdesc.c',
  'gstpesfilter.c',
  'plugin.c',
  'resindvdbin.c',
  'resindvdsrc.c',
  'rsndec.c',
  'rsninputselector.c',
  'rsnparsetter.c',
]

dvdnav_dep = dependency('dvdnav', version : '>= 4.1.2', required : false)

if dvdnav_dep.found()
  gstresindvd = library('gstresindvd',
    resindvd_sources,
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [ gstvideo_dep, gstpbutils_dep, dvdnav_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
