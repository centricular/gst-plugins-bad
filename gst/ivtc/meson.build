ivtc_sources = [
  'gstivtc.c',
  'gstcombdetect.c',
]

gstivtc = library('gstivtc',
  ivtc_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
