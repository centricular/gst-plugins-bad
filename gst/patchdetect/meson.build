patch_sources = [
  'gstpatchdetect.c',
]

gstpatchdetect = library('gstpatchdetect',
  patch_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep, libm],
)
