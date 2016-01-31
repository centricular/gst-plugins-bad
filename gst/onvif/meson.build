onvif_sources = [
  'gstrtponvif.c',
  'gstrtponvifparse.c',
  'gstrtponviftimestamp.c',
]

gstonvif = library('gstonvif',
  onvif_sources,
  c_args : gst_plugins_bad_args,
  include_directories : gst_plugins_bad_incs,
  dependencies : [ gstrtp_dep, gstbase_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
