tta_sources = [
  'gsttta.c',
  'gstttaparse.c',
  'gstttadec.c',
]

gsttta = library('gsttta',
  tta_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
