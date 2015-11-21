gstadpcmenc_sources = [
  'adpcmenc.c'
]

gstadpcmenc = library('gstadpcmenc',
  gstadpcmenc_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
