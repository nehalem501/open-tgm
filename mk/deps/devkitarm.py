#!/usr/bin/env python3

from os import getenv
from pathlib import Path
from . import devkitpro

DEVKITARM = getenv('DEVKITARM')
if DEVKITARM is None:
    raise Exception('Please set DEVKITARM in your environment')

PATH = [Path(DEVKITARM).joinpath('bin')] + devkitpro.PATH
