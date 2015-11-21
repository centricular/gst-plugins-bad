midi_sources = [
  'midi.c',
  'midiparse.c',
]

gstmidi = library('gstmidi',
  midi_sources,
  c_args : core_args,
  include_directories : core_incs,
  dependencies : [gstbase_dep, gsttag_dep, libm],
)
