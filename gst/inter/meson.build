inter_sources = [
  'gstinteraudiosink.c',
  'gstinteraudiosrc.c',
  'gstintersubsink.c',
  'gstintersubsrc.c',
  'gstintervideosink.c',
  'gstintervideosrc.c',
  'gstinter.c',
  'gstintersurface.c',
]

gstinter = library('gstinter',
  inter_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
