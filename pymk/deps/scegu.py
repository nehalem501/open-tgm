#!/usr/bin/env python3

from pathlib import Path
from .expand import expand
from .rule import to_src_rule, Rule, Build

def target(self, entry, options, build_info):
    # TODO split stuff from psp.py
    pass
