debugutils_sources = [
  'gstdebugspy.c',
  'debugutilsbad.c',
  'fpsdisplaysink.c',
  'gstchecksumsink.c',
  'gstchopmydata.c',
  'gstcompare.c',
  'gstwatchdog.c',
]

debugutils_headers = [
  'gstchecksumsink.h',
  'gstchopmydata.h',
  'gstcompare.h',
  'gstdebugspy.h',
  'gstwatchdog.h',
]

mkmarsh = find_program('gen_marshal.py')

dbgmarsh_h = custom_target('dbgmarsh_h',
  output : 'debugutils-marshal.h',
  input : 'debugutils-marshal.list',
  command : [mkmarsh, '@OUTPUT@', '@INPUT@', 'debugutils'])

dbgmarsh_c = custom_target('dbgmarsh_c',
  output : 'debugutils-marshal.c',
  input : 'debugutils-marshal.list',
  command : [mkmarsh, '@OUTPUT@', '@INPUT@', 'debugutils'])


gstdebugutils = library('gstdebugutils',
  debugutils_sources, dbgmarsh_c, dbgmarsh_h,
  c_args : core_args,
  include_directories : [core_incs, include_directories('../../gst-libs/gst/mpegts')],
  dependencies : [gstbase_dep, gstvideo_dep],
)
