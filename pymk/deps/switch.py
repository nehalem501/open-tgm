#!/usr/bin/env python3

from pathlib import Path
from . import devkitpro, devkita64
from .rule import Rule, Build, Variable

PATH = devkita64.PATH

def target(self, entry, options, build_info):
    self.path += PATH
    self.headers += [Path(devkitpro.DEVKITPRO).joinpath('libnx').joinpath('include')]
    self.lib_dirs += [Path(devkitpro.DEVKITPRO).joinpath('libnx').joinpath('lib')] # TODO

    "-specs=/opt/devkitpro/libnx/switch.specs"

    #self.variables += [Variable('app_title', entry.values['app_title'])]
    #self.variables += [Variable('app_description', entry.values['app_description'])]
    #self.variables += [Variable('app_author', entry.values['app_author'])]

    app_icon = build_info.root_dir.joinpath(Path(entry.values['app_icon']))

    rom = self.binary.with_suffix('.nro')
    self.binary = self.build_dir.joinpath(self.binary.name)
    #smdh = self.binary.with_suffix('.smdh')
    #self.rules += [Rule('smdhtool', 'smdhtool --create "$app_title" "$app_description" "$app_author" $in $out', 'generating $out')]
    #self.builds += [Build('$smdh', 'smdhtool', str(app_icon))]
    #self.variables += [Variable('smdh', str(smdh))]
    self.variables += [Variable('app_icon', str(app_icon))]

    self.rules += [Rule('elf2nro', 'elf2nro $in $out --icon=$app_icon', 'generating Switch rom $out')]
    self.builds += [Build(str(rom), 'elf2nro', str(self.binary), str(app_icon))]
