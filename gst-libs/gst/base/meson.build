badbase_sources = [
  'gstaggregator.c'
]

gstbadbase = library('gstbadbase-' + api_version,
  badbase_sources,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
