dvdspu_sources = [
  'gstdvdspu.c',
  'gstdvdspu-render.c',
  'gstspu-vobsub.c',
  'gstspu-vobsub-render.c',
  'gstspu-pgs.c',
]

gstdvdspu = library('gstdvdspu',
  dvdspu_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
