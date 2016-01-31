smoothstreaming_sources = [
  'gstmssdemux.c',
  'gstmssmanifest.c',
  'gstsmoothstreaming-plugin.c',
]

xml28_dep = dependency('libxml-2.0', version : '>= 2.8', required : false)

if xml28_dep.found()
  gstmss = library('gstsmoothstreaming',
    smoothstreaming_sources,
    c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
    include_directories : gst_plugins_bad_incs,
    link_with : [ gstadaptivedemux, gstcodecparsers ],
    dependencies : [ gst_dep, xml28_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
