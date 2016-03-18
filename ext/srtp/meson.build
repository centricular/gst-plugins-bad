srtp_sources = [
  'gstsrtp.c',
  'gstsrtpdec.c',
  'gstsrtpenc.c',
]

srtp_dep = dependency('libsrtp', required : false)
if not srtp_dep.found() and cc.has_function('srtp_init', prefix : '#include <srtp/srtp.h>')
  srtp_dep = cc.find_library('srtp', required : false)
endif

if srtp_dep.found()
  mkenums = find_program('srtp_mkenum.py')
  gstsrtp_h = custom_target('gstsrtpenum_h',
    output : 'gstsrtp-enumtypes.h',
    input : 'gstsrtp.h',
    command : [ mkenums, '@OUTPUT@', '@INPUT@' ])

  gstsrtp_c = custom_target('gstsrtpenum_c',
    output : 'gstsrtp-enumtypes.c',
    input : 'gstsrtp.h',
    depends : [gstsrtp_h],
    command : [ mkenums, '@OUTPUT@', '@INPUT@' ])

  gstsrtp = library('gstsrtp',
    srtp_sources, gstsrtp_c, gstsrtp_h,
    c_args : gst_plugins_bad_args,
    include_directories : gst_plugins_bad_incs,
    dependencies : [ gstrtp_dep, gstvideo_dep, srtp_dep ],
    install : true,
    install_dir : plugins_install_dir,
  )
endif
