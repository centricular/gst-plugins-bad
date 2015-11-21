asfmux_sources = [
  'gstasfmux.c',
  'gstasfobjects.c',
  'gstasfparse.c',
  'gstrtpasfpay.c',
  'gstasf.c',
]

gstasfmux = library('gstasfmux',
  asfmux_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstrtp_dep],
)
