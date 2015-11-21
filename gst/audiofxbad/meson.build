audiofxbad_sources = [
  'gstaudiofxbad.c',
  'gstaudiochannelmix.c',
]

gstaudiofxbad = library('gstaudiofxbad',
  audiofxbad_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep, libm],
)
