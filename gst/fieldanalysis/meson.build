fielda_sources = [
  'gstfieldanalysis.c'
]

field_c = configure_file(input : 'gstfieldanalysisorc-dist.c',
  output : 'gstfieldanalysisorc.c',
  configuration : configuration_data()
)

field_h = configure_file(input : 'gstfieldanalysisorc-dist.h',
  output : 'gstfieldanalysisorc.h',
  configuration : configuration_data()
)

gstfieldanalysis = library('gstfieldanalysis',
  fielda_sources, field_c,
  c_args : gst_plugins_bad_args,
  include_directories : [configinc],
  dependencies : [gstbase_dep, gstvideo_dep, orc_dep],
  install : true,
  install_dir : plugins_install_dir,
)
