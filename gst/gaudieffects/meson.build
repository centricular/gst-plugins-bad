gaudio_sources = [
  'gstburn.c',
  'gstchromium.c',
  'gstdilate.c',
  'gstdodge.c',
  'gstexclusion.c',
  'gstgaussblur.c',
  'gstsolarize.c',
  'gstplugin.c',
]

gaudio_c = configure_file(input : 'gstgaudieffectsorc-dist.c',
  output : 'gstgaudieffectsorc.c',
  configuration : configuration_data()
)

gaudio_h = configure_file(input : 'gstgaudieffectsorc-dist.h',
  output : 'gstgaudieffectsorc.h',
  configuration : configuration_data()
)


gstgaudioeffects = library('gstgaudioeffects',
  gaudio_sources, gaudio_c,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstvideo_dep, orc_dep, libm],
  install : true,
  install_dir : plugins_install_dir,
)
