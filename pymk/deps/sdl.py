#!/usr/bin/env python3

import subprocess

def target(self, entry, options, build_info):
    result = subprocess.run(['sdl-config', '--cflags'], stdout=subprocess.PIPE)
    self.cflags += [result.stdout.decode('utf-8').strip()]
    self.cxxflags += [result.stdout.decode('utf-8').strip()]

    result = subprocess.run(['sdl-config', '--libs'], stdout=subprocess.PIPE)
    self.ldflags += [result.stdout.decode('utf-8').strip()]
