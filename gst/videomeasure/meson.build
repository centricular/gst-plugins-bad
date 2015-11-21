measure_sources = [
  'gstvideomeasure.c',
  'gstvideomeasure_ssim.c',
  'gstvideomeasure_collector.c',
]

gstvideomeasure = library('gstvideomeasure',
  measure_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep, libm],
)
