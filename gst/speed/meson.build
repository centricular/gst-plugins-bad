speed_sources = [
  'gstspeed.c'
]

gstspeed = library('gstspeed',
  speed_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
