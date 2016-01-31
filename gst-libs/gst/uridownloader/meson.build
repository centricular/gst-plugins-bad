urid_sources = [
  'gstfragment.c',
  'gsturidownloader.c',
]

gsturidownloader = library('gsturidownloader-' + api_version,
  urid_sources,
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  dependencies : [ gstbase_dep ],
)
