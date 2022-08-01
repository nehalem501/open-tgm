#!/usr/bin/env python3

import os
import copy
import platform

from . import configure
from . import ninja
from .entry import BuildEntry, PlatformEntry
from .globals import BUILD_INI, DATA_DIR, SRC_DIR, CORE_DIR, CORE_HEADERS_DIR, MODES_DIR, PLATFORMS_DIR, GPU_DIR, GPU_SRC_DIR, GPU_BACKENDS_DIR, BIN_DIR, BUILD_DIR, RESOURCES_DIR, TOOLS_DIR
from .target import Target, TargetData
from pymk import entry

def find_all(a_str, sub):
    start = 0
    while True:
        start = a_str.find(sub, start)
        if start == -1: return
        yield start
        start += 1

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
        self.data_dir = root_dir.joinpath(DATA_DIR)
        self.resources_dir = self.data_dir.joinpath(RESOURCES_DIR)
        self.platform_entries = [PlatformEntry(e) for e in scan_subdirs(self.src_dir, [PLATFORMS_DIR])]
        self.platforms = [p.name for p in self.platform_entries]
        self.gpu_root_dir = self.src_dir.joinpath(GPU_DIR)
        self.toplevel = BuildEntry(self.root_dir)
        self.default_target = self.toplevel.values['default_target']
        self.bin_dir = root_dir.joinpath(BIN_DIR)
        self.build_dir = root_dir.joinpath(BUILD_DIR)
        self.platforms_dir = self.src_dir.joinpath(PLATFORMS_DIR)
        self.core_headers_dir = self.src_dir.joinpath(CORE_HEADERS_DIR)
        self.scripts_dir = self.root_dir.joinpath('pymk')

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
        core_entry = self.toplevel
        target_entry = self.get_platform_entry(target)

        binary = self.get_target_bin_dir(target).joinpath(self.toplevel.name)

        common_flags = ['-DTARGET_' + target.upper()]
        if options.debug:
            common_flags += [core_entry.values['debug_flags']] # TODO optimisation levels and types
        else:
            common_flags += ['-O2'] # TODO optimisation levels and types

        additional_entries = self.core_entries + [target_entry]

        data = TargetData(
            entry=core_entry,
            additional_entries=additional_entries,
            options=options,
            build_dir=self.get_target_build_dir(target),
            binary=binary,
            library=None,
            common_flags=common_flags,
            headers=[self.core_headers_dir, target_entry.dir]
        )
        target = Target(data)
        return target

def build_target(target, options, build_info):
    build_info.finish_init()
    # TODO ninja file path
    file = build_info.root_dir.joinpath(target).with_suffix('.ninja')
    build = build_info.get_target(target, options)
    config = configure.run(build, '', file)
    add_host_tools(config, options, build.tools, build_info)
    ninja.run(config, options)
    return build.binary

def add_host_tools(config, options, tools, build_info):
    new_options = copy.deepcopy(options)
    new_options.debug = False
    tools_dir = build_info.src_dir.joinpath(TOOLS_DIR)
    tool_entries = [BuildEntry(e) for e in scan_subdirs(tools_dir, tools)]
    for entry in tool_entries:
        build_dir = build_info.build_dir.joinpath(TOOLS_DIR).joinpath(entry.name)
        name = build_dir.joinpath(entry.name)
        binary = None
        library = None
        if 'binary' in entry.values:
            binary = name
        elif 'library' in entry.values:
            if os.name == 'nt':
                library = name.with_suffix('.dll')
            else:
                if platform.system() == 'Darwin':
                    library = name.with_suffix('.dylib')
                else:
                    library = name.with_suffix('.so')

        data = TargetData(
            entry=entry,
            additional_entries=[],
            options=options,
            build_dir=build_dir,
            binary=binary,
            library=library,
            common_flags=[],
            headers=[entry.dir]
        )
        build = Target(data)
        # TODO add to single ninja file instead of running separately
        config = configure.run(build, '', entry.name + '.ninja')
        ninja.run(config, options)
