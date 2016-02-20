debugutils_sources = [
  'gstdebugspy.c',
  'gsterrorignore.c',
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

gstdebugutils = library('gstdebugutils',
  debugutils_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
  install : true,
  install_dir : plugins_install_dir,
)
