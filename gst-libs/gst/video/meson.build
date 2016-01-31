badvideo_sources = [
  'gstvideoaggregator.c',
]


gstbadvideo = library('gstbadvideo-' + api_version,
  badvideo_sources,
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  dependencies : [gst_dep],
)
