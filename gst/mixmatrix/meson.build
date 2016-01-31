mixmat_sources = [
  'mixmatrix.c',
]

gstmixmatrix = library('gstmixmatrix',
  mixmat_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
  install : true,
  install_dir : plugins_install_dir,
)
