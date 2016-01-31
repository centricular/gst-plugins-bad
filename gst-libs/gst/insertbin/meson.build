insert_sources = [
  'gstinsertbin.c'
]

gstinsertbin = library('gstinsertbin-' + api_version,
  insert_sources,
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  dependencies : [gst_dep],
)
