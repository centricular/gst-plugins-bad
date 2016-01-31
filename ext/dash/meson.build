dash_sources = [
  'gstdashdemux.c',
  'gstisoff.c',
  'gstmpdparser.c',
  'gstplugin.c',
]

xml2_dep = dependency('libxml-2.0', version : '>= 2.8', required : false)
if xml2_dep.found()
  gstsouphttpsrc = library('gstdash',
    dash_sources,
    c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
    include_directories : gst_plugins_bad_incs,
    link_with : gstadaptivedemux,
    dependencies : [ gsttag_dep, gstnet_dep, gio_dep, xml2_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
