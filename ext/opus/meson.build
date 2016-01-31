opus_sources = [
  'gstopus.c',
  'gstopuscommon.c',
  'gstopusdec.c',
  'gstopusenc.c',
  'gstopusheader.c',
  'gstopusparse.c',
  'gstrtpopusdepay.c',
  'gstrtpopuspay.c',
]

opus_dep = dependency('opus', version : '>= 0.9.4', required : false)

if opus_dep.found()
  gstopus = library('gstopus',
    opus_sources,
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [ gstrtp_dep, gstpbutils_dep, gstaudio_dep, opus_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
