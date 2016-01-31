vbi_sources = [
  'gstvbidec.c',
  'vbidata.c',
  'vbiscreen.c',
]

gstvbidec = library('gstvbidec',
  vbi_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
  install : true,
  install_dir : plugins_install_dir,
)
