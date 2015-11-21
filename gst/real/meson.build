real_sources = [
  'gstrealvideodec.c',
  'gstrealaudiodec.c',
  'gstreal.c',
]

gstreal = library('gstreal',
  real_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
