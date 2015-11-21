audiovis_sources = [
  'plugin.c',
  'gstaudiovisualizer.c',
  'gstspacescope.c',
  'gstspectrascope.c',
  'gstsynaescope.c',
  'gstwavescope.c',
]

gstaudiovisualizers = library('gstaudiovisualizers',
  audiovis_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep, gstvideo_dep, gstfft_dep, libm],
)
