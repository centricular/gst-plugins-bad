adpcmdec_sources = [
  'adpcmdec.c'
]

gstadpcmdec = library('gstacdpcmdec',
  adpcmdec_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
  install : true,
  install_dir : plugins_install_dir,
)
