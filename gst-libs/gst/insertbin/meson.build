insert_sources = [
  'gstinsertbin.c'
]

gstinsertbin = library('gstinsertbin-' + api_version,
  insert_sources,
  c_args : core_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
