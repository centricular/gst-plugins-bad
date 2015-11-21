pnm_sources = [
  'gstpnmutils.c',
  'gstpnm.c',
  'gstpnmdec.c',
  'gstpnmenc.c',
]

gstpnm = library('gstpnm',
  pnm_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
