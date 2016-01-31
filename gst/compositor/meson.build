compositor_sources = [
  'blend.c',
  'compositor.c',
]

compo_c = configure_file(input : 'compositororc-dist.c',
  output : 'compositororc.c',
  configuration : configuration_data()
)

compo_h = configure_file(input : 'compositororc-dist.h',
  output : 'compositororc.h',
  configuration : configuration_data()
)

gstcompositor = library('gstcompositor',
  compositor_sources, compo_c,
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  link_with : [ gstbadvideo, gstbadbase ],
  dependencies : [ gstvideo_dep, gstbase_dep, orc_dep, libm ],
  install : true,
  install_dir : plugins_install_dir,
)
