measure_sources = [
  'gstvideomeasure.c',
  'gstvideomeasure_ssim.c',
  'gstvideomeasure_collector.c',
]

gstvideomeasure = library('gstvideomeasure',
  measure_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstvideo_dep, libm],
  install : true,
  install_dir : plugins_install_dir,
)
