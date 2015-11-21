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

gst = library('gstphotography-' + api_version,
  photography_sources, photoenum_h, photoenum_c,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
