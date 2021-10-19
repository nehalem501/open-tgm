#!/usr/bin/env python3

from configparser import ConfigParser
from itertools import chain

from .globals import BUILD_INI
from .deps.requirement import Requirement

class BuildEntry:
    def __init__(self, dir):
        self.dir = dir
        self.name = dir.name
        self.file = dir.joinpath(BUILD_INI)
        self.values = dict()
        self.requires = []
        parser = ConfigParser()
        with open(self.file) as lines:
            default_section = 'build'
            lines = chain(['[' + default_section + ']'], lines)
            parser.read_file(lines)
            fields = parser.options(default_section)
            for field in fields:
                if field == 'requires':
                    self.requires += [Requirement(self, r) for r in parser[default_section][field].split()]
                    continue
                self.values[field] = parser[default_section][field]

    def __repr__ (self):
        return "BuildEntry('" + self.name + "')"

class PlatformEntry(BuildEntry):
    def __init__(self, dir):
        super().__init__(dir)
        self.gpu = ('gpu_backend' in self.values)
        if self.gpu:
            self.gpu_backend = self.values['gpu_backend']
            self.gpu_tile_sizes = self.values['gpu_tile_sizes'].split()
            self.gpu_assets_builtin = (self.values.get('gpu_assets') == 'builtin')

    def __repr__ (self):
        return "PlatformEntry('" + self.name + "')"
