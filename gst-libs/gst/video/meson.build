badvideo_sources = [
  'videoconvert.c',
  'gstvideoaggregator.c',
  'gstcms.c',
]

badvid_c = configure_file(input : 'bad-video-orc-dist.c',
  output : 'bad-video-orc.c',
  configuration : configuration_data()
)

badvid_h = configure_file(input : 'bad-video-orc-dist.h',
  output : 'bad-video-orc.h',
  configuration : configuration_data()
)


gstbadvideo = library('gstbadvideo-' + api_version,
  badvideo_sources,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  dependencies : [gst_dep],
)
