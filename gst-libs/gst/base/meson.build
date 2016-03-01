badbase_sources = [
  'gstaggregator.c'
]

gstbadbase = library('gstbadbase-' + api_version,
  badbase_sources,
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : gst_plugins_bad_incs,
  version : libversion,
  soversion : soversion,
  dependencies : [gst_dep],
  # Only used with MSVC
  module_defs_file: meson.source_root() + '/win32/common/libgstbadbase.def',
)

gstbadbase_dep = declare_dependency(link_with : gstbadbase)
