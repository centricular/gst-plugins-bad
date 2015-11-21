frei0r_sources = [
  'gstfrei0r.c',
  'gstfrei0rfilter.c',
  'gstfrei0rsrc.c',
  'gstfrei0rmixer.c',
]

gstfrei0r = library('gstfrei0r',
  frei0r_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
