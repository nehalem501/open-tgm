#!/usr/bin/env python3

from os import getenv
from pathlib import Path

DEVKITPRO = getenv('DEVKITPRO')
if DEVKITPRO is None:
    raise Exception('Please set DEVKITPRO in your environment')

PATH = [Path(DEVKITPRO).joinpath('tools').joinpath('bin')]
