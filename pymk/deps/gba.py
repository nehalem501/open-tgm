#!/usr/bin/env python3

from pathlib import Path
from . import devkitpro, devkitarm
from .rule import Rule, Build, Variable

PATH = devkitarm.PATH

def target(self, entry, options, build_info):
    self.path += PATH
    self.headers += [Path(devkitpro.DEVKITPRO).joinpath('libgba').joinpath('include')]
    self.lib_dirs += [Path(devkitpro.DEVKITPRO).joinpath('libgba').joinpath('lib')] # TODO

    rom = self.binary.with_suffix('.gba')
    self.binary = self.build_dir.joinpath(self.binary.name)

    # TODO multiple commands using && won't work on windows
    self.rules += [Rule('gbarom', 'arm-none-eabi-objcopy -O binary $in $out && gbafix $out', 'generating GBA rom $out')]
    self.builds += [Build(str(rom), 'gbarom', str(self.binary))]
