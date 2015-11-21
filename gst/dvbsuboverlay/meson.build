subover_sources = [
  'dvb-sub.c',
  'gstdvbsuboverlay.c',
]

gstdvbsuboverlay = library('gstdvbsuboverlay',
  subover_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
