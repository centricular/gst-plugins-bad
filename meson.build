project('gstreamer-plugins-bad', 'c', version : '1.4.5',
  default_options : ['c_std=gnu99', 'warning_level=1'])

version_str = meson.project_version()
varr = version_str.split('.')
version_major = varr[0]
version_minor = varr[1]
version_micro = varr[2]
version_nano = 1
api_version = '1.0'

cc = meson.get_compiler('c')
cdata = configuration_data()
check_headers = [
  ['HAVE_DLFCN_H', 'dlfcn.h'],
  ['HAVE_FCNTL_H', 'fcntl.h'],
  ['HAVE_HIGHGUI_H', 'highgui.h'],
  ['HAVE_INTTYPES_H', 'inttypes.h'],
  ['HAVE_MEMORY_H', 'memory.h'],
  ['HAVE_MSACM_H', 'msacm.h'],
  ['HAVE_NETINET_IN_H', 'netinet/in.h'],
  ['HAVE_NETINET_IP_H', 'netinet/ip.h'],
  ['HAVE_NETINET_TCP_H', 'netinet/tcp.h'],
  ['HAVE_OPENCV2_HIGHGUI_HIGHGUI_C_H', 'opencv2/highgui/highgui_c.h'],
  ['HAVE_PTHREAD_H', 'pthread.h'],
  ['HAVE_STDINT_H', 'stdint.h'],
  ['HAVE_STDLIB_H', 'stdlib.h'],
  ['HAVE_STRINGS_H', 'strings.h'],
  ['HAVE_STRING_H', 'string.h'],
  ['HAVE_SYS_PARAM_H', 'sys/param.h'],
  ['HAVE_SYS_SOCKET_H', 'sys/socket.h'],
  ['HAVE_SYS_STAT_H', 'sys/stat.h'],
  ['HAVE_SYS_TIME_H', 'sys/time.h'],
  ['HAVE_SYS_TYPES_H', 'sys/types.h'],
  ['HAVE_SYS_UTSNAME_H', 'sys/utsname.h'],
  ['HAVE_UNISTD_H', 'unistd.h'],
  ['HAVE_WINDOWS_H', 'windows.h'],
  ['HAVE_WININET_H', 'wininet.h'],
  ['HAVE_WINSOCK2_H', 'winsock2.h'],
  ['HAVE_WS2TCPIP_H', 'ws2tcpip.h'],
]

foreach h : check_headers
  if cc.has_header(h.get(1))
    cdata.set(h.get(0), 1)
  endif
endforeach

check_functions = [
# check token HAVE_ACM
# check token HAVE_ANDROID_MEDIA
# check token HAVE_APEXSINK
# check token HAVE_APPLE_MEDIA
# check token HAVE_ASSRENDER
# check token HAVE_AVC
# check token HAVE_AVFOUNDATION
# check token HAVE_BLUEZ
# check token HAVE_BZ2
# check token HAVE_CFLOCALECOPYCURRENT
# check token HAVE_CFPREFERENCESCOPYAPPVALUE
# check token HAVE_CHROMAPRINT
# check token HAVE_CPU_ALPHA
# check token HAVE_CPU_ARM
# check token HAVE_CPU_CRIS
# check token HAVE_CPU_CRISV32
# check token HAVE_CPU_HPPA
# check token HAVE_CPU_I386
# check token HAVE_CPU_IA64
# check token HAVE_CPU_M68K
# check token HAVE_CPU_MIPS
# check token HAVE_CPU_PPC
# check token HAVE_CPU_PPC64
# check token HAVE_CPU_S390
# check token HAVE_CPU_SPARC
# check token HAVE_CPU_X86_64
# check token HAVE_CURL
# check token HAVE_DAALA
# check token HAVE_DASH
# check token HAVE_DC1394
  ['HAVE_DCGETTEXT', 'dcgettext', '#include<libintl.h>'],
# check token HAVE_DECKLINK
# check token HAVE_DIRECT3D
# check token HAVE_DIRECTDRAW
# check token HAVE_DIRECTFB
# check token HAVE_DIRECTSOUND
# check token HAVE_DOWHILE_MACROS
# check token HAVE_DTS
# check token HAVE_DVB
# check token HAVE_EXPERIMENTAL
# check token HAVE_EXTERNAL
# check token HAVE_FAAC
# check token HAVE_FAAD
# check token HAVE_FBDEV
# check token HAVE_FIONREAD_IN_SYS_FILIO
# check token HAVE_FIONREAD_IN_SYS_IOCTL
# check token HAVE_FLITE
# check token HAVE_FLUIDSYNTH
  ['HAVE_GETPAGESIZE', 'getpagesize', '#include<unistd.h>'],
# check token HAVE_GETTEXT
# check token HAVE_GL
# check token HAVE_GLCHAR
# check token HAVE_GLEGLIMAGEOES
# check token HAVE_GLINTPTR
# check token HAVE_GLSIZEIPTR
# check token HAVE_GME
  ['HAVE_GMTIME_R', 'gmtime_r', '#include<time.h>'],
# check token HAVE_GRAPHENE
# check token HAVE_GSETTINGS
# check token HAVE_GSM
# check token HAVE_GUDEV
# check token HAVE_HLS
# check token HAVE_ICONV
# check token HAVE_IOS
# check token HAVE_JPEG
# check token HAVE_KATE
# check token HAVE_LADSPA
# check token HAVE_LIBGCRYPT
# check token HAVE_LIBGME_ACCURACY
# check token HAVE_LIBMMS
# check token HAVE_LIBNSL
# check token HAVE_LIBSOCKET
# check token HAVE_LIBUSB
# check token HAVE_LIBVISUAL
# check token HAVE_LINSYS
# check token HAVE_LRDF
# check token HAVE_LV2
# check token HAVE_MIMIC
  ['HAVE_MMAP', 'mmap', '#include<sys/mman.h>'],
# check token HAVE_MODPLUG
# check token HAVE_MPEG2ENC
# check token HAVE_MPG123
# check token HAVE_MPLEX
# check token HAVE_MUSEPACK
# check token HAVE_MYTHTV
# check token HAVE_NAS
# check token HAVE_NEON
# check token HAVE_NETTLE
# check token HAVE_OFA
# check token HAVE_OPENAL
# check token HAVE_OPENCV
# check token HAVE_OPENEXR
# check token HAVE_OPENJPEG
# check token HAVE_OPENJPEG_1
# check token HAVE_OPENNI2
# check token HAVE_OPENSLES
# check token HAVE_OPUS
# check token HAVE_ORC
# check token HAVE_OSX
# check token HAVE_OSX_VIDEO
# check token HAVE_PNG
# check token HAVE_PVR
# check token HAVE_QUICKTIME
# check token HAVE_RDTSC
# check token HAVE_RESINDVD
# check token HAVE_RSVG
# check token HAVE_RSVG_2_36_2
# check token HAVE_RTMP
# check token HAVE_SBC
# check token HAVE_SCHRO
# check token HAVE_SDL
# check token HAVE_SHM
# check token HAVE_SMOOTHSTREAMING
# check token HAVE_SNDFILE
# check token HAVE_SNDIO
# check token HAVE_SOUNDTOUCH
# check token HAVE_SOUNDTOUCH_1_4
# check token HAVE_SPANDSP
# check token HAVE_SPC
# check token HAVE_SRTP
# check token HAVE_SSH2
# check token HAVE_TELETEXTDEC
# check token HAVE_TIGER
# check token HAVE_TIMIDITY
# check token HAVE_UVCH264
# check token HAVE_VALGRIND
# check token HAVE_VCD
# check token HAVE_VDPAU
# check token HAVE_VIDEOTOOLBOX
# check token HAVE_VIDEOTOOLBOX_10_9_6
# check token HAVE_VOAACENC
# check token HAVE_VOAMRWBENC
# check token HAVE_WASAPI
# check token HAVE_WAYLAND
# check token HAVE_WEBP
# check token HAVE_WILDMIDI
# check token HAVE_WILDMIDI_0_2_2
# check token HAVE_WIN32
# check token HAVE_WININET
# check token HAVE_WINKS
# check token HAVE_WINSCREENCAP
# check token HAVE_X11
# check token HAVE_XVID
# check token HAVE_ZBAR
]

foreach f : check_functions
  if cc.has_function(f.get(1), prefix : f.get(2))
    cdata.set(f.get(0), 1)
  endif
endforeach

cdata.set('SIZEOF_CHAR', cc.sizeof('char'))
cdata.set('SIZEOF_INT', cc.sizeof('int'))
cdata.set('SIZEOF_LONG', cc.sizeof('long'))
cdata.set('SIZEOF_SHORT', cc.sizeof('short'))
cdata.set('SIZEOF_VOIDP', cc.sizeof('void*'))

# FIXMES
cdata.set('VERSION', '"@0@"'.format(version_str))
cdata.set('DEFAULT_VIDEOSRC', '"FIXME"')
cdata.set('PACKAGE', '"FIXME"')
cdata.set('PACKAGE_NAME', '"FIXME"')
cdata.set('GETTEXT_PACKAGE', '"FIXME"')
cdata.set('GST_PACKAGE_NAME', '"FIXME"')
cdata.set('GST_PACKAGE_ORIGIN', '"FIXME"')
cdata.set('GST_LICENSE', '"FIXME"')

# Mandatory GST deps
gst_dep = dependency('gstreamer-1.0')
gstapp_dep = dependency('gstreamer-app-1.0')
gstvideo_dep = dependency('gstreamer-video-1.0')
gstpbutils_dep = dependency('gstreamer-pbutils-1.0')
gsttag_dep = dependency('gstreamer-tag-1.0')
gstfft_dep = dependency('gstreamer-fft-1.0')
gstaudio_dep = dependency('gstreamer-audio-1.0')
gstbase_dep = dependency('gstreamer-base-1.0')
gstriff_dep = dependency('gstreamer-riff-1.0')
gstrtp_dep = dependency('gstreamer-rtp-1.0')
gstnet_dep = dependency('gstreamer-net-1.0')
gstsdp_dep = dependency('gstreamer-sdp-1.0')
gstrtsp_dep = dependency('gstreamer-rtsp-1.0')
gstcheck_dep = dependency('gstreamer-check-1.0')
gstcontroller_dep = dependency('gstreamer-controller-1.0')

orc_dep = dependency('orc-0.4')
zlib_dep = dependency('zlib')
gio_dep = dependency('gio-2.0')
gl_dep = dependency('gl')

x_dep = dependency('x11', required : false)
xfixes_dep = dependency('xfixes', required : false)
xdamage_dep = dependency('xdamage', required : false)

if gl_dep.found()
  cdata.set('HAVE_GL', 1)
endif

libm = find_library('m', required : false)
bz2lib = find_library('bz2', required : false)
jpeglib = find_library('jpeg', required : false)

configure_file(input : 'config.h.meson',
  output : 'config.h',
  configuration : cdata)

core_args = ['-DHAVE_CONFIG_H']
core_incs = include_directories('.', 'gst-libs')

subdir('gst-libs')
subdir('gst')
