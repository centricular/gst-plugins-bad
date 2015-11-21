jpegf_sources = [
  'gstjpegformat.c',
  'gstjpegparse.c',
  'gstjifmux.c',
]

gstjpegformat = library('gstjpegformat',
  jpegf_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gsttag_dep],
)
