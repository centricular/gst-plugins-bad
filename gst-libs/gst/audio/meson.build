badaudio_sources = [
  'gstaudioaggregator.c',
]


gstbadaudio = library('gstbadaudio-' + api_version,
  badaudio_sources,
  c_args : gst_plugins_bad_args + [ '-DGST_USE_UNSTABLE_API' ],
  include_directories : gst_plugins_bad_incs,
  link_with : gstbadbase,
  dependencies : [ gstaudio_dep, gst_dep ],
)
