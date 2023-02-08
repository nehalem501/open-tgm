#!/usr/bin/env python3

from os import getenv
from pathlib import Path
from . import devkitpro

DEVKITA64 = str(Path(devkitpro.DEVKITPRO).joinpath('devkitA64'))
PATH = [Path(DEVKITA64).joinpath('bin')] + devkitpro.PATH
