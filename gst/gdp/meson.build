gdp_sources = [
  'dataprotocol.c',
  'gstgdp.c',
  'gstgdppay.c',
  'gstgdpdepay.c',
]

gstdgp = library('gstgdp',
  gdp_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
