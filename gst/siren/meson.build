siren_sources = [
  'gstsiren.c',
  'gstsirendec.c',
  'gstsirenenc.c',
  'common.c',
  'dct4.c',
  'decoder.c',
  'encoder.c',
  'huffman.c',
  'rmlt.c',
]

gstsiren = library('gstsiren',
  siren_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep],
)
