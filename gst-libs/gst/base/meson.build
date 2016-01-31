badbase_sources = [
  'gstaggregator.c'
]

gstbadbase = library('gstbadbase-' + api_version,
  badbase_sources,
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : gst_plugins_bad_incs,
  dependencies : [gst_dep],
)
