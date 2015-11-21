vparse_sources = [
  'plugin.c',
  'h263parse.c',
  'gsth263parse.c',
  'gstdiracparse.c',
  'dirac_parse.c',
  'gsth264parse.c',
  'gstmpegvideoparse.c',
  'gstmpeg4videoparse.c',
  'gstpngparse.c',
  'gstvc1parse.c',
  'gsth265parse.c',
]

gstvideoparsersbad = library('gstvideoparsersbad',
  vparse_sources,
  c_args : core_args,
  include_directories : core_incs,
  link_with : [gstcodecparsers],
  dependencies : [gstbase_dep, gstpbutils_dep, gstvideo_dep],
)
