camerabin_sources = [
  'gstcamerabin-enum.c',
  'gstcamerabinpreview.c',
  'gstbasecamerasrc.c',
]

gstbasecamerabin = library('gstbasecamerabinsrc-' + api_version,
  camerabin_sources,
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : [configinc, libsinc],
  version : libversion,
  soversion : soversion,
  install : true,
  dependencies : [gstbase_dep, gstapp_dep],
  vs_module_defs: vs_module_defs_dir + 'libgstbasecamerabinsrc.def',
)

gstbasecamerabin_dep = declare_dependency(link_with : gstbasecamerabin,
  include_directories : [libsinc])
