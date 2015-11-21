autocon_sources = [
  'gstautoconvert.c',
  'gstautovideoconvert.c',
  'plugin.c',
]

gstautoconvert = library('gstautoconvert',
  autocon_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
