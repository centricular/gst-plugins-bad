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
  c_args : core_args,
  include_directories : core_incs,
  link_with : [gstbadbase],
  dependencies : [gstbase_dep, gstvideo_dep, orc_dep, libm],
)
