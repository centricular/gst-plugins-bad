id3_sources = [
  'gstid3mux.c',
  'id3tag.c',
]

gstid3tag = library('gstid3tag',
  id3_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gsttag_dep],
)
