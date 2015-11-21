accurip_sources = [
  'gstaccurip.c',
]

gstaccurip = library('gstaccurip',
  accurip_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
