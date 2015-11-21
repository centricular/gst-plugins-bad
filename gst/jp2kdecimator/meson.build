jp2_sources = [
  'gstjp2kdecimator.c',
  'jp2kcodestream.c',
]

gstjp2kdecimator = library('gstjp2kdecimator',
  jp2_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
