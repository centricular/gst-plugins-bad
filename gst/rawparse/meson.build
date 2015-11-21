raw_sources = [
  'gstrawparse.c',
  'gstaudioparse.c',
  'gstvideoparse.c',
  'plugin.c',
]

gstrawparse = library('gstrawparse',
  raw_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep, gstaudio_dep],
)
