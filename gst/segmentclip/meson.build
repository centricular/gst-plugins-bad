segment_sources = [
  'gstsegmentclip.c',
  'gstaudiosegmentclip.c',
  'gstvideosegmentclip.c',
  'plugin.c',
]

gstsegmentclip = library('gstsegmentclip',
  segment_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
