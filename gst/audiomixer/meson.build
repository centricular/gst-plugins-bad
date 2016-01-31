audiomixer_sources = [
  'gstaudiomixer.c',
  'gstaudiointerleave.c',
]

aumix_c = configure_file(input : 'gstaudiomixerorc-dist.c',
  output : 'gstaudiomixerorc.c',
  configuration : configuration_data()
)

aumix_h = configure_file(input : 'gstaudiomixerorc-dist.h',
  output : 'gstaudiomixerorc.h',
  configuration : configuration_data()
)


gstaudiomixer = library('gstaudiomixer',
  audiomixer_sources, aumix_c,
  c_args : core_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : core_incs,
  link_with : [ gstbadaudio, gstbadbase ],
  dependencies : [ gstaudio_dep, gstbase_dep, orc_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
