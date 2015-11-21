games_sources = [
  'gstvideoimage.c',
  'gstpuzzle.c',
]

gstpuzzle = library('gstpuzzle',
  games_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
