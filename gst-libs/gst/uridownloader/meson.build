urid_sources = [
  'gstfragment.c',
  'gsturidownloader.c',
]

gsturidownloader = library('gsturidownloader-' + api_version,
  urid_sources,
  c_args : core_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
