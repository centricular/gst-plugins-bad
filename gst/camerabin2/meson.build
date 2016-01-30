camerabin2_sources = [
  'gstdigitalzoom.c',
  'gstviewfinderbin.c',
  'camerabingeneral.c',
  'gstwrappercamerabinsrc.c',
  'gstcamerabin2.c',
  'gstplugin.c',
]

gstcamerabin2 = library('gstcamerabin',
  camerabin2_sources,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  link_with : gstbasecamerabin,
  dependencies : [ gstphotography_dep, gsttag_dep, gstapp_dep, gstpbutils_dep, gstbase_dep ],
)
