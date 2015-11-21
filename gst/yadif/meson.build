yadif_sources = [
  'gstyadif.c',
  'vf_yadif.c',
  'yadif.c'
]

gstyadif = library('gstyadif',
  yadif_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
