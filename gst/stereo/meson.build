stereo_sources = [
  'gststereo.c',
]

gststereo = library('gststereo',
  stereo_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
