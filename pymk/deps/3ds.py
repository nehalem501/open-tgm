#!/usr/bin/env python3

from pathlib import Path
from . import devkitpro, devkitarm
from .rule import Rule, Build, Variable

PATH = devkitarm.PATH

def target(self, entry, options, build_info):
    self.path += PATH
    self.headers += [Path(devkitpro.DEVKITPRO).joinpath('libctru').joinpath('include')]
    self.lib_dirs += [Path(devkitpro.DEVKITPRO).joinpath('libctru').joinpath('lib')] # TODO

    self.variables += [Variable('app_title', entry.values['app_title'])]
    self.variables += [Variable('app_description', entry.values['app_description'])]
    self.variables += [Variable('app_author', entry.values['app_author'])]

    app_icon = build_info.root_dir.joinpath(Path(entry.values['app_icon']))

    rom = self.binary.with_suffix('.3ds')
    self.binary = self.build_dir.joinpath(self.binary.name)
    smdh = self.binary.with_suffix('.smdh')
    self.rules += [Rule('smdhtool', 'smdhtool --create "$app_title" "$app_description" "$app_author" $in $out', 'generating $out')]
    self.builds += [Build('$smdh', 'smdhtool', str(app_icon))]
    self.variables += [Variable('smdh', str(smdh))]

    self.rules += [Rule('3dsxtool', '3dsxtool $in $out --smdh=$smdh', 'generating 3DS rom $out')]
    self.builds += [Build(str(rom), '3dsxtool', str(self.binary), str(smdh))]
