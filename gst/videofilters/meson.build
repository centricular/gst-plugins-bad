vfilt_sources = [
  'gstzebrastripe.c',
  'gstscenechange.c',
  'gstvideodiff.c',
  'gstvideofiltersbad.c',
]

gstvideofiltersbad = library('gstvideofiltersbad',
  vfilt_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [ gstvideo_dep, gstbase_dep, orc_dep, libm ],
  install : true,
  install_dir : plugins_install_dir,
)
