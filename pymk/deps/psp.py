#!/usr/bin/env python3

import subprocess
import os
from pathlib import Path
#from . import devkitpro, devkitarm
from .expand import get_path
from .rule import Rule, Build, Variable

#PATH = devkitarm.PATH

PSPDEV = os.getenv('PSPDEV')
if PSPDEV is None:
    raise Exception('Please set PSPDEV in your environment')

PATH = [Path(PSPDEV).joinpath('bin')]

def target(self, entry, options, build_info):
    self.path += PATH
    my_env = os.environ.copy()
    my_env["PATH"] = get_path(self.path) + my_env["PATH"]
    PSPSDK = Path(
        subprocess.run(['psp-config', '--pspsdk-path'], env=my_env, stdout=subprocess.PIPE)
        .stdout
        .decode('utf-8')
        .strip())

    self.headers += [Path(PSPSDK).joinpath('include')]
    self.lib_dirs += [Path(PSPSDK).joinpath('lib')] # TODO

    psp_eboot_title = entry.values['psp_eboot_title']
    psp_eboot_icon = entry.values['psp_eboot_icon']
    psp_eboot_icon1 = entry.values['psp_eboot_icon1']
    psp_eboot_unkpng = entry.values['psp_eboot_unkpng']
    psp_eboot_pic1 = entry.values['psp_eboot_pic1']
    psp_eboot_snd0 = entry.values['psp_eboot_snd0']
    psp_eboot_psar = entry.values['psp_eboot_psar']

    rom = self.binary.parent.joinpath('EBOOT.PBP')
    self.binary = self.build_dir.joinpath(self.binary.name)
    sfo = self.binary.parent.joinpath('PARAM.SFO')
    stripped = self.binary.parent.joinpath('stripped_' + self.binary.name)

    # TODO multiple commands using && won't work on windows
    self.rules += [Rule('strip', 'psp-fixup-imports $in && psp-strip $in -o $out', 'strip $out')]
    self.rules += [Rule('mksfo', f'mksfo \'{psp_eboot_title}\' $out', 'mksfo $out')]
    self.rules += [Rule('pack', f'pack-pbp $out {str(sfo)} {psp_eboot_icon} {psp_eboot_icon1} {psp_eboot_unkpng} {psp_eboot_pic1} {psp_eboot_snd0} $in {psp_eboot_psar}', 'pack $out')]

    self.builds += [Build(str(stripped), 'strip', str(self.binary))]
    self.builds += [Build(str(sfo), 'mksfo', None)]
    self.builds += [Build(str(rom), 'pack', str(stripped), dependencies=[str(sfo)])]
