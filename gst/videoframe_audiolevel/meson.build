videoframe_audiolevel_sources = [
  'gstvideoframe-audiolevel.c',
]

gstvideoframe_audiolevel = library('gstvideoframe_audiolevel',
  videoframe_audiolevel_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [ gstvideo_dep, gstaudio_dep ],
  install : true,
  install_dir : plugins_install_dir,
)
