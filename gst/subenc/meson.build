subenc_sources = [
  'gstsrtenc.c',
  'gstsubenc.c',
  'gstwebvttenc.c',
]

gstsubenc = library('gstsubenc',
  subenc_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
