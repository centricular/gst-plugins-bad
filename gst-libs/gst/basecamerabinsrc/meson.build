camerabin_sources = [
  'gstcamerabin-enum.c',
  'gstcamerabinpreview.c',
  'gstbasecamerasrc.c',
]

gstbasecamerabin = library('gstbasecamerabinsrc-' + api_version,
  camerabin_sources,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
