badvideo_sources = [
  'gstvideoaggregator.c',
]


gstbadvideo = library('gstbadvideo-' + api_version,
  badvideo_sources,
  c_args : core_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
