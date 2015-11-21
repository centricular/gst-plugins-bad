cdxaparse_sources = [
  'gstcdxaparse.c',
  'gstvcdparse.c',
]

gstcdxaparse = library('gstcdxaparse',
  cdxaparse_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstriff_dep],
)
