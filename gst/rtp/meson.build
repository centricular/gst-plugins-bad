rtp_bad_sources = [
  'gstrtp.c',
  'gstrtph265depay.c',
  'gstrtph265pay.c',
]

gstrtpbad = library('gstrtpbad',
  rtp_bad_sources,
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  link_with : gstcodecparsers,
  dependencies : [ gstpbutils_dep, gstrtp_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
