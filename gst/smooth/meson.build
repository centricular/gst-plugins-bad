smooth_sources = [
  'gstsmooth.c',
]

gstsmooth = library('gstsmooth',
  smooth_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
