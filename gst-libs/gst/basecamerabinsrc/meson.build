camerabin_sources = [
  'gstcamerabin-enum.c',
  'gstcamerabinpreview.c',
  'gstbasecamerasrc.c',
]

gstbasecamerabin = library('gstbasecamerabinsrc-' + api_version,
  camerabin_sources,
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : gst_plugins_bad_incs,
  version : libversion,
  soversion : soversion,
  dependencies : [gstbase_dep, gstapp_dep],
  # Only used with MSVC
  module_defs_file: meson.source_root() + '/win32/common/libgstbasecamerabinsrc.def',
)
