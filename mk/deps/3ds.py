#!/usr/bin/env python3

from pathlib import Path
from . import devkitpro, devkitarm, rule, requirement
from .expand import expand
from .rule import to_src_rule

PATH = devkitarm.PATH

def target(self, entry, build_info):
    self.path += PATH
    self.headers += [Path(devkitpro.DEVKITPRO).joinpath('libctru').joinpath('include')]

    # TODO
    png_files = expand(entry.dir, entry.values['png_files'])
    #png_files = [to_src_rule(build_info.root_dir, build_info.src_dir, self.build_dir, p, '.png.o') for p in png_files]
    for p in png_files:
        self.builtin_data += [Path(p)]
