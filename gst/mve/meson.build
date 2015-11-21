mve_sources = [
  'gstmve.c',
  'gstmvemux.c',
  'gstmvedemux.c',
  'mveaudiodec.c',
  'mvevideodec8.c',
  'mvevideodec16.c',
  'mveaudioenc.c',
  'mvevideoenc8.c',
  'mvevideoenc16.c',
]

gstmve = library('gstmve',
  mve_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, libm],
)
