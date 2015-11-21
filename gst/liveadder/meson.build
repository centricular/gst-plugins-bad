liveadder_sources = [
  'liveadder.c',
]

gstliveadder = library('gstliveadder',
  liveadder_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
