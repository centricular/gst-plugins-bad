hdv_sources = [
  'gsthdvparse.c'
]

gsthdvparse = library('gsthdvparse',
  hdv_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, libm],
)
