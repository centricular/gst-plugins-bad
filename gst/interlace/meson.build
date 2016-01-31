interlace_sources = [
  'gstinterlace.c',
]

gstinterlace = library('gstinterlace',
  interlace_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
  install : true,
  install_dir : plugins_install_dir,
)
