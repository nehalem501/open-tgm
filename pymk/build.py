#!/usr/bin/env python3

from configparser import ConfigParser
from itertools import chain
from pathlib import Path

from . import configure
from .globals import BUILD_INI, SRC_DIR, CORE_DIR, CORE_HEADERS_DIR, MODES_DIR, PLATFORMS_DIR, GPU_DIR, GPU_SRC_DIR, GPU_BACKENDS_DIR, BIN_DIR, BUILD_DIR
from .target import Target
from .deps.requirement import Requirement

def find_all(a_str, sub):
    start = 0
    while True:
        start = a_str.find(sub, start)
        if start == -1: return
        yield start
        start += 1

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
        """for v in self.values:
            occurences = find_all(v, '$')
            if occurences == 0:
                continue
            line = ''
            previous = 0
            for o in occurences:
                line += v[previous:o]
                previous = o
                if v[o + 1] == '(':
                    pass"""

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

def scan_dir(dir):
    entries = [dir] if dir.joinpath(BUILD_INI).exists() else []
    for d in dir.iterdir():
        if d.is_dir():
            entries += scan_dir(d)
    return entries

def scan_dirs(dirs):
    entries = []
    for d in dirs:
        entries += scan_dir(d)
    return entries

def scan_subdirs(root_dir, dirs):
    entries = []
    for d in dirs:
        entries += scan_dir(root_dir.joinpath(d))
    return entries

class BuildInfo:
    def __init__(self, root_dir):
        self.root_dir = root_dir
        self.src_dir = root_dir.joinpath(SRC_DIR)
        self.platform_entries = [PlatformEntry(e) for e in scan_subdirs(self.src_dir, [PLATFORMS_DIR])]
        self.platforms = [p.name for p in self.platform_entries]
        self.gpu_root_dir = self.src_dir.joinpath(GPU_DIR)
        self.toplevel = BuildEntry(self.root_dir)
        self.default_target = self.toplevel.values['default_target']
        self.bin_dir = root_dir.joinpath(BIN_DIR)
        self.build_dir = root_dir.joinpath(BUILD_DIR)
        self.platforms_dir = self.src_dir.joinpath(PLATFORMS_DIR)
        self.core_headers_dir = self.src_dir.joinpath(CORE_HEADERS_DIR)

    def finish_init(self):
        self.core_entries = [BuildEntry(e) for e in scan_subdirs(self.src_dir, [CORE_DIR, MODES_DIR])]
        self.gpu_src_dir = self.gpu_root_dir.joinpath(GPU_SRC_DIR)
        self.gpu_entry = BuildEntry(self.gpu_src_dir)
        self.gpu_backends_entries = [BuildEntry(e) for e in scan_subdirs(self.gpu_root_dir, [GPU_BACKENDS_DIR])]

    def get_target_build_dir(self, target):
        # TODO handle special targets such as SDL
        return self.build_dir.joinpath(target)

    def get_target_bin_dir(self, target):
        # TODO handle special targets such as SDL
        return self.bin_dir.joinpath(target)

    def get_platform_entry(self, platform):
        for p in self.platform_entries:
            if p.name == platform:
                return p

    def get_gpu_backend_entry(self, backend):
        for b in self.gpu_backends_entries:
            if b.name == backend:
                return b

    def get_target(self, target, options):
        target = Target(target, options, self)
        #target.load_requirements(self)
        return target

def build_target(target, options, build_info):
    build_info.finish_init()
    configure.run(build_info.get_target(target, options), options, build_info)
