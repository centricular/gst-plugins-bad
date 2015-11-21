fover_sources = [
  'gstfaceoverlay.c',
]

gstfaceoverlay = library('gstfaceoverlay',
  fover_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
