sdp_sources = [
  'gstsdpelem.c',
  'gstsdpdemux.h',
  'gstsdpdemux.c'
]

gstsdpelem = library('gstspdelem',
  sdp_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstrtp_dep, gstsdp_dep],
)
