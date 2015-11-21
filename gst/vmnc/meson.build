vmnc_sources = [
  'vmncdec.c',
]

gstvmnc = library('gstvmnc',
  vmnc_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
