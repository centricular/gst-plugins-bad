gstadaptivedemux = library('gstadaptivedemux-' + api_version,
  'gstadaptivedemux.c',
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : gst_plugins_bad_incs,
  link_with : gsturidownloader,
  version : libversion,
  soversion : soversion,
  dependencies : [gst_dep, gstbase_dep],
  # Only used with MSVC
  module_defs_file: meson.source_root() + '/win32/common/libgstadaptivedemux.def',
)
