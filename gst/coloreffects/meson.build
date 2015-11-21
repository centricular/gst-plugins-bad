coloreffects_sources = [
  'gstplugin.c',
  'gstcoloreffects.c',
  'gstchromahold.c',
]

gstcoloreffects = library('gstcoloreffects',
  coloreffects_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
