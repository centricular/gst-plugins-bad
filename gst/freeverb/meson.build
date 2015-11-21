freeverb_sources = [
  'gstfreeverb.c',
]

gstfreeverb = library('gstfreeverb',
  freeverb_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
