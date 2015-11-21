bayer_sources = [
  'gstbayer.c',
  'gstbayer2rgb.c',
  'gstrgb2bayer.c',
]

bayer_c = configure_file(input : 'gstbayerorc-dist.c',
  output : 'gstbayerorc.c',
  configuration : configuration_data()
)

bayer_h = configure_file(input : 'gstbayerorc-dist.h',
  output : 'gstbayerorc.h',
  configuration : configuration_data()
)



gstbayer = library('gstbayer',
  bayer_sources, bayer_c,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep, orc_dep],
)
