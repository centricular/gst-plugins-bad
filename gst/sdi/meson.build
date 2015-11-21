sdi_sources = [
  'gstsdidemux.c',
  'gstsdimux.c',
]

gstsdi = library('gstsdi',
  sdi_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
