festival_sources = [
  'gstfestival.c'
]

gstfestival = library('gstfestival',
  festival_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
