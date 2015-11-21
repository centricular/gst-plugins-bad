insert_sources = [
  'gstinsertbin.c'
]

gstinsertbin = library('gst' + api_version,
  insert_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gst_dep],
)
