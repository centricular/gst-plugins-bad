audiomixer_sources = [
  'gstaudiomixer.c'
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
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, orc_dep],
)
