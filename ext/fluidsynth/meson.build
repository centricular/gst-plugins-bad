fluidsynth_dep = dependency('fluidsynth', version : '>= 1.0', required : false)

if fluidsynth_dep.found()
  gstfluidsynth = library('gstfluidsynth',
    'gstfluiddec.c',
    c_args : gst_plugins_bad_args,
    include_directories : [configinc],
    dependencies : [gst_dep, fluidsynth_dep],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
