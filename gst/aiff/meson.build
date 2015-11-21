aiff_sources = [
  'aiff.c', 'aiffmux.c', 'aiffparse.c',
]

gstaiff = library('gstaiff',
  aiff_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gsttag_dep, gstaudio_dep, libm],
)
