codecparser_sources = [
  'gstmpegvideoparser.c',
  'gsth264parser.c',
  'gstvc1parser.c',
  'gstmpeg4parser.c',
  'gsth265parser.c',
  'gstvp8parser.c',
  'gstvp8rangedecoder.c',
  'parserutils.c',
  'nalutils.c',
  'dboolhuff.c',
  'vp8utils.c',
  'gstmpegvideometa.c',
]

cp_args = [
  '-DGST_USE_UNSTABLE_API',
  '-Dvp8_norm=gst_codecparsers_vp8_norm',
  '-Dvp8dx_start_decode=gst_codecparsers_vp8dx_start_decode',
  '-Dvp8dx_bool_decoder_fill=gst_codecparsers_vp8dx_bool_decoder_fill',
]

gstcodecparsers = library('gstcodecparsers-' + api_version,
  codecparser_sources,
  c_args : core_args + cp_args,
  include_directories : core_incs,
  dependencies : [gst_dep, libm],
)
