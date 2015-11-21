bluez_sources = [
  'bluez-plugin.c',
  'gsta2dpsink.c',
  'gstavdtpsink.c',
  'gstavdtpsrc.c',
  'gstavdtputil.c'
]

gstbluez = library('gstbluez',
  bluez_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstaudio_dep, gstrtp_dep, dbus_dep],
)
