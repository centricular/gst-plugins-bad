urid_sources = [
  'gstfragment.c',
  'gsturidownloader.c',
]

gsturidownloader = library('gstdownloader-' + api_version,
  urid_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gst_dep],
)
