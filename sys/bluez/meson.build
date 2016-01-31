bluez_sources = [
  'bluez-plugin.c',
  'gsta2dpsink.c',
  'gstavdtpsink.c',
  'gstavdtpsrc.c',
  'gstavdtputil.c'
]

if bluez_dep.found() and gio_unix_dep.found()

  # FIXME: do we really need the meson.current_build_dir() here? Shouldn't
  # the custom command be executed with the current build directoy as working
  # directory? Without this, bluez.[ch] are created in the top-level build dir!
  bluez_ch = custom_target('bluez_ch',
    output : [ 'bluez.h', 'bluez.c' ] ,
    input : 'org.bluez.xml',
    command : [ find_program('gdbus-codegen'),
                '--c-namespace=Bluez',
                '--generate-c-code=' + meson.current_build_dir() + '/bluez',
                '--interface-prefix=org.bluez',
                '@INPUT@' ])

  gstbluez = library('gstbluez',
    bluez_sources, bluez_ch,
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [ gstaudio_dep, gstrtp_dep, gstbase_dep, gio_unix_dep, bluez_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
