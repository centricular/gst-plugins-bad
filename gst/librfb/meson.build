rfb_sources = [
  'rfbbuffer.c',
  'rfbdecoder.c',
  'd3des.c',
]

rfb = library('rfb', rfb_sources,
  c_args : core_args,
  include_directories : [core_incs, include_directories('..')],
  dependencies : [gst_dep, gio_dep],
)

gstrfbsrc = library('gstrfbsrc',
  'gstrfbsrc.c',
  c_args : core_args,
  include_directories : [core_incs, include_directories('..')],
  link_with : rfb,
  dependencies : [gstbase_dep, gstvideo_dep],
)
