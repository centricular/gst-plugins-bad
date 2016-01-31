gstadaptivedemux = library('gstadaptivedemux-' + api_version,
  'gstadaptivedemux.c',
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  link_with : gsturidownloader,
  dependencies : [gst_dep],
)
