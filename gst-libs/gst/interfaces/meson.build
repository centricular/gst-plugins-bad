photography_sources = [
  'photography.c',
]

photo_headers = [
  'photography.h',
]

mkenums = find_program('build_mkenum.py')

photoenum_h = custom_target('photoenum_h',
  output : 'photography-enumtypes.h',
  input : photo_headers,
  command : [mkenums, '@OUTPUT@', '@INPUT@'])

photoenum_c = custom_target('photoenum_c',
  output : 'photography-enumtypes.c',
  input : photo_headers,
  command : [mkenums, '@OUTPUT@', '@INPUT@'])

gstphotography = library('gstphotography-' + api_version,
  photography_sources, photoenum_h, photoenum_c,
  c_args : gst_plugins_bad_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : gst_plugins_bad_incs,
  version : libversion,
  soversion : soversion,
  dependencies : [gst_dep],
  # Only used with MSVC
  module_defs_file: meson.source_root() + '/win32/common/libgstphotography.def',
)

gstphotography_dep = declare_dependency(link_with : gstphotography,
  sources : [ photoenum_h ])
