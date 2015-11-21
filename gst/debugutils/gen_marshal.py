#!/usr/bin/env python3

import sys, os, subprocess

ofilename = sys.argv[1]
ifilename = sys.argv[2]
basename = sys.argv[3]

if ofilename.endswith('.h'):
    prefix = ''
    body = subprocess.check_output(['glib-genmarshal', '--header',
                                    '--prefix=__gst_%s_marshal' % basename,
                                    ifilename])
else:
    prefix = '#include"%s-marshal.h"\n' % basename
    body = subprocess.check_output(['glib-genmarshal', '--body',
                                    '--prefix=__gst_%s_marshal' % basename,
                                    ifilename])

open(ofilename, 'w').write(prefix + body.decode('utf-8'))
