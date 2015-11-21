gl_sources = [
  'gstgldisplay.c',
  'gstglcontext.c',
  'gstglmemory.c',
  'gstglbufferpool.c',
  'gstglfilter.c',
  'gstglshader.c',
  'gstglshadervariables.c',
  'gstglcolorconvert.c',
  'gstgldownload.c',
  'gstglupload.c',
  'gstgluploadmeta.c',
  'gstglwindow.c',
  'gstglapi.c',
  'gstglfeature.c',
  'gstglutils.c',
  'gstglframebuffer.c',
]

glconf = configuration_data()

glconf.set10('GST_GL_HAVE_OPENGL', gl_dep.found())

if x_dep.found()
  gl_sources += [
    'x11/gstgldisplay_x11.c',
    'x11/gstglwindow_x11.c',
    'x11/x11_event_source.c',
    'x11/gstglcontext_glx.c',
]
  glconf.set('GST_GL_HAVE_WINDOW_X11', 1)
  glconf.set('GST_GL_HAVE_PLATFORM_GLX', 1)
endif

# Add rest of gl config here.

configure_file(input : 'gstglconfig.h.meson',
  output : 'gstglconfig.h',
  configuration : glconf)

gstgl = library('gstgl-' + api_version,
  gl_sources,
  c_args : core_args + ['-DGST_USE_UNSTABLE_API'],
  include_directories : core_incs,
  dependencies : [gstbase_dep, gstvideo_dep],
)
