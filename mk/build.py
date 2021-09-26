#!/usr/bin/env python3

from configparser import ConfigParser
from itertools import chain
from pathlib import Path

from . import configure
from .target import Target

BUILD_INI = 'build.ini'

SRC_DIR = 'src'

CORE_DIR = 'core'
CORE_HEADERS_DIR = 'include'
MODES_DIR = 'modes'
PLATFORMS_DIR = 'platforms'
GPU_DIR = 'gpu'
GPU_SRC_DIR = 'src'
GPU_BACKENDS_DIR = 'backends'

BIN_DIR = 'bin'
BUILD_DIR = 'build'

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
        parser = ConfigParser()
        with open(self.file) as lines:
            default_section = 'build'
            lines = chain(['[' + default_section + ']'], lines)
            parser.read_file(lines)
            fields = parser.options(default_section)
            for field in fields:
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

class PlatformEntry(BuildEntry):
    def __init__(self, dir):
        super().__init__(self, dir)
        self.gpu = (self.values['type'] == 'gpu')

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
        self.toplevel = BuildEntry(root_dir)
        self.core_entries = [BuildEntry(e) for e in scan_subdirs(self.src_dir, [CORE_DIR, MODES_DIR])]
        self.platform_entries = [BuildEntry(e) for e in scan_subdirs(self.src_dir, [PLATFORMS_DIR])]
        self.platforms = [p.name for p in self.platform_entries]
        gpu_root = self.src_dir.joinpath(GPU_DIR)
        self.gpu = BuildEntry(gpu_root.joinpath(GPU_SRC_DIR))
        self.gpu_backends_entries = [BuildEntry(e) for e in scan_subdirs(gpu_root, [GPU_BACKENDS_DIR])]
        self.default_target = self.toplevel.values['default_target']
        self.bin_dir = root_dir.joinpath(BIN_DIR)
        self.build_dir = root_dir.joinpath(BUILD_DIR)
        self.platforms_dir = self.src_dir.joinpath(PLATFORMS_DIR)
        self.core_headers_dir = self.src_dir.joinpath(CORE_HEADERS_DIR)

    def get_target_build_dir(self, target):
        # TODO handle special targets such as SDL
        return self.root_dir.joinpath(BUILD_DIR).joinpath(target)

    def get_platform_entry(self, platform):
        for p in self.platform_entries:
            if p.name == platform:
                return p

    def get_target(self, target, debug):
        return Target(target, debug, self)

def build_target(target, debug, build_info):
    #print("build target: " + target + ", debug=" + str(debug))
    configure.run(build_info.get_target(target, debug), debug, build_info)
