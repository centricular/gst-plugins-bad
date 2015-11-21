mpegd_sources = [
  'plugin.c',
  'gstmpegdemux.c',
  'gstpesfilter.c',
]

gstmpedpsdemux = library('gstmpegpsdemux',
  mpegd_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gsttag_dep, gstpbutils_dep],
)
