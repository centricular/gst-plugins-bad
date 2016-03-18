dca_dep = dependency('libdca', required : false)

if not dca_dep.found() and cc.has_function('dca_init', prefix : '#include <dca.h>')
  dca_dep = cc.find_library('dca', required : false)
endif

if dca_dep.found()
  gstdtsdec = library('gstdtsdec',
    'gstdtsdec.c',
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [gstaudio_dep, orc_dep, dca_dep],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
