silence_sources = [
  'gstremovesilence.c',
  'vad_private.c',
]

gstremovesilence = library('gstremovesilence',
  silence_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
