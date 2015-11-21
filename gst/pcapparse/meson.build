capp_sources = [
  'gstpcapparse.c',
  'gstirtspparse.c',
  'plugin.c',
]

gstpcapparse = library('gstpcapparse',
  capp_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
