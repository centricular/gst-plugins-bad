flite_sources = [
  'gstflite.c',
  'gstflitetestsrc.c',
]

flite_libs = [
  'flite',
  'flite_cmu_us_kal',
  'flite_usenglish',
  'flite_cmulex'
]

flite_deps = [ ]
foreach flite_lib : flite_libs
  dep = find_library(flite_lib, required : false)
  if dep.found()
    flite_deps += [ dep ]
  endif
endforeach

if flite_deps.length() == flite_libs.length() and cc.has_function('flite_init', prefix : '#include <flite/flite.h>')
  gstflite = library('gstflite',
    flite_sources,
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [ gstaudio_dep ] + flite_deps,
    install : true,
    install_dir : plugins_install_dir,
  )
endif
