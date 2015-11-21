rtjpeg_sources = [
  'gstrtjpeg.c',
  'gstrtjpegenc.c',
  'gstrtjpegdec.c',
  'RTjpeg.c',
]

gstrtjpeg = library('gstrtjpeg',
  rtjpeg_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep],
)
