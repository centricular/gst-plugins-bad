ivfparse_sources = [
  'gstivfparse.c',
]

gstivfparse = library('gstivfparse',
  ivfparse_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [ gstbase_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
