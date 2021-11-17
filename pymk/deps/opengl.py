#!/usr/bin/env python3

import os
import platform

def target(self, entry, options, build_info):
    #if os.name == 'nt':
    #    self.ldflags += [''] # TODO
    #else:
        if platform.system() == 'Darwin':
            self.ldflags += ['-framework OpenGL']
        else:
            self.libs += ['GL', 'GLU']
