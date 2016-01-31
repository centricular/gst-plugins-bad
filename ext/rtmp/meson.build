rtmp_sources = [
  'gstrtmp.c',
  'gstrtmpsink.c',
  'gstrtmpsrc.c',
]

rtmp_dep = dependency('librtmp', required : false)

if rtmp_dep.found()
  gstrtmp = library('gstrtmp',
    rtmp_sources,
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [ gstbase_dep, rtmp_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
