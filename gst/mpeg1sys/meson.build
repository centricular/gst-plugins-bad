mpeg1_sources = [
  'gstmpeg1systemencode.c',
  'buffer.c',
  'systems.c',
]

gstmpeg1systemencode = library('gstmpeg1systemencode',
  mpeg1_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
