d3dvideosink_sources = [
  'd3dhelpers.c',
  'd3dvideosink.c',
]

if host_system == 'windows' and cc.has_header('d3dx9tex.h')
  # Headers from the June 2010 DirectX SDK -- the last SDK to ship D3DX
  d3dxinc = include_directories('d3dx_include')
  d3dvideosink_dep = [cc.find_library('d3d9'), cc.find_library('gdi32')]

  gstd3dvideosink = library('gstd3dvideosink',
    d3dvideosink_sources,
    c_args : gst_plugins_bad_args,
    include_directories : [configinc, d3dxinc],
    dependencies : [gstvideo_dep] + d3dvideosink_dep,
    install : true,
    install_dir : plugins_install_dir)
endif
