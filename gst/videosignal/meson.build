vsignal_sources = [
  'gstvideosignal.c',
  'gstvideoanalyse.c',
  'gstsimplevideomarkdetect.c',
  'gstsimplevideomark.c',
]

gstvideosignal = library('gstvideosignal',
  vsignal_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
