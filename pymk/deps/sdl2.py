#!/usr/bin/env python3

import subprocess

from pymk.deps.libs import decode_libs

def target(self, entry, options, build_info):
    result = subprocess.run(['sdl2-config', '--cflags'], stdout=subprocess.PIPE)
    self.cflags += [result.stdout.decode('utf-8').strip()]
    self.cxxflags += [result.stdout.decode('utf-8').strip()]

    result = subprocess.run(['sdl2-config', '--libs'], stdout=subprocess.PIPE)
    tuple = decode_libs(result.stdout.decode('utf-8'))
    self.libs += tuple.libs
    self.ldflags += tuple.ldflags
