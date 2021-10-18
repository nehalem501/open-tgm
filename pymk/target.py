#!/usr/bin/env python3

import importlib
import os
import subprocess
import sys

from pathlib import Path

from .entry import BuildEntry
from .globals import GPU_DIR, GPU_BACKENDS_DIR, DATA_DIR, RESOURCES_DIR, LIBS_DIR
from .deps.expand import expand
from .deps.rule import Rule, Build, SrcRule, to_src_rule, to_data_rule

def headers_to_flags(headers):
    return ['-I' + str(h) for h in headers]

def libs_to_flags(libs):
    return ['-l' + str(l) for l in libs]

def lib_dirs_to_flags(lib_dirs):
    return ['-L' + str(l) for l in lib_dirs]

class Target:
    cc = 'cc'
    cxx = 'c++'
    link = None

    c_std = 'c99'
    cxx_std = 'c++11'

    asflags = []
    cflags = []
    cxxflags = []
    ldflags = []

    headers = []
    libs = []
    static_libs = []
    lib_dirs = []

    src_c = []
    src_cpp = []

    builtin_data = []
    shaders = []
    textures = []

    objects = []
    binary = 'a.out'

    path = []
    rules = []
    builds = []
    variables = []

    def __init__(self, target, options, build_info):
        self.name = target

        self.build_dir = build_info.get_target_build_dir(target)
        self.root_dir = build_info.root_dir
        self.scripts_dir = build_info.root_dir.joinpath('pymk')
        self.binary = build_info.get_target_bin_dir(target).joinpath(build_info.toplevel.name)
        self.build_file = build_info.root_dir.joinpath(target).with_suffix('.ninja')

        #if 'name' in build_info.toplevel.values:
        #    self.binary = build_info.toplevel.values['name']

        if 'c_std' in build_info.toplevel.values: #TODO target override
            self.c_std = build_info.toplevel.values['c_std']

        if 'cxx_std' in build_info.toplevel.values: #TODO target override
            self.cxx_std = build_info.toplevel.values['cxx_std']

        self.headers += [build_info.core_headers_dir]

        for e in build_info.core_entries:
            if 'src_c' in e.values:
                self.src_c += expand(e.dir, e.values['src_c'])
            if 'src_cpp' in e.values:
                self.src_cpp += expand(e.dir, e.values['src_cpp'])

        common_flags = []
        if options.debug:
            common_flags += [build_info.toplevel.values['debug_flags'], '-O2'] # TODO optimisation levels and types
        else:
            common_flags += ['-O2'] # TODO optimisation levels and types

        common_flags += [build_info.toplevel.values['common_flags']]
        common_flags += ['-DTARGET_' + target.upper()]

        self.cflags += common_flags
        self.cxxflags += common_flags

        self.target_entry = build_info.get_platform_entry(target)

        self.headers += [self.target_entry.dir]

        self.load_entry(self.target_entry)
        self.load_requirements(build_info)

        if self.static_libs:
            libs_dir = build_info.src_dir.joinpath(LIBS_DIR)
            static_libs_entries = []
            for l in self.static_libs:
                entry = BuildEntry(libs_dir.joinpath(l))
                self.load_entry(entry)
                pass

        self.cflags += headers_to_flags(self.headers)
        self.cxxflags += headers_to_flags(self.headers)

        self.cflags += ['-std=' + self.c_std]
        self.cxxflags += ['-std=' + self.cxx_std]

        self.libs = libs_to_flags(self.libs)
        self.ldflags += lib_dirs_to_flags(self.lib_dirs)

        if self.link is None:
            self.link = self.cxx

        #if self.builtin_data:
        #    self.builtin_data = [to_src_rule_keep_suffix(build_info.root_dir, build_info.root_dir, self.build_dir, s, '.cpp') for s in self.builtin_data]

        if self.shaders:
            # shaders are always builtin
            self.shaders = [to_data_rule(self.root_dir, self.build_dir, s) for s in self.shaders]
            pass

        self.builtin_data += self.shaders

        if self.target_entry.gpu:
            resources_dir = self.root_dir.joinpath(DATA_DIR).joinpath(RESOURCES_DIR)
            ini_files = []
            for size in self.target_entry.gpu_tile_sizes:
                dir = resources_dir.joinpath(size)
                ini_files += expand(dir, '*.ini')

            png_files = [f.with_suffix('.png') for f in ini_files]

            #self.textures = [to_data_rule(self.root_dir, self.build_dir, f) for f in png_files]

            if self.target_entry.gpu_assets_builtin:
                # assets objects should be built in build_dir/data/_px
                # we need also to take care of data_info and other headers generation
                self.builtin_data += [to_data_rule(self.root_dir, self.build_dir, f) for f in png_files]
            else:
                # create copy target, asset detection and loading should happen at runtime
                pass
                #self.textures = [to_src_rule_keep_suffix(build_info.root_dir, build_info.root_dir, self.build_dir, t, '.cpp') for t in self.textures]


        #for r in self.builtin_data:
        #    self.src_cpp += [Path(r.output_cpp)]

        self.binary = str(self.binary)

        self.src_c = [to_src_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s, '.o') for s in self.src_c]
        self.src_cpp = [to_src_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s, '.o') for s in self.src_cpp]

        self.objects += [r.output for r in self.src_c] + [r.output for r in self.src_cpp]
        for r in self.builtin_data:
            self.objects += [r.output_object]

        # TODO environment override for common variables
        #env_keys = set([
        #    'AS', 'CC', 'CXX', 'ASFLAGS', 'CFLAGS', 'CXXFLAGS', 'LDFLAGS',
        #    'HOST_CC', 'HOST_CXX', 'HOST_CFLAGS', 'HOST_CXXFLAGS', 'HOST_LDFLAGS'])
        #configure_env = dict((k, os.environ[k]) for k in os.environ if k in env_keys)
        #if configure_env:
        #    config_str = ' '.join([k + '=' + pipes.quote(configure_env[k])
        #                        for k in configure_env])
        #    n.variable('configure_env', config_str + '$ ')
        #n.newline()

        try:
            my_env = os.environ.copy()
            if self.path:
                my_env["PATH"] = self.get_path() + my_env["PATH"]

            proc = subprocess.Popen(
                [self.cxx, '-fdiagnostics-color', '-c', '-x', 'c++', '/dev/null',
                '-o', '/dev/null'],
                stdout=open(os.devnull, 'wb'),
                stderr=subprocess.STDOUT,
                env=my_env)
            if proc.wait() == 0:
                self.cflags += ['-fdiagnostics-color']
                self.cxxflags += ['-fdiagnostics-color']
        except:
            pass

    def get_path(self):
        return ':'.join([str(p) for p in self.path]) + ':'

    def load_entry(self, entry):
        values = entry.values

        if 'name' in values:
            self.binary = self.binary.with_name(values['name'])

        if 'cc' in values:
            self.cc = values['cc']
        if 'cxx' in values:
            self.cxx = values['cxx']
        if 'link' in values:
            self.link = values['link']

        if 'common_flags' in values:
            self.cflags += [values['common_flags']]
            self.cxxflags += [values['common_flags']]
        if 'cflags' in values:
            self.cflags += [values['cflags']]
        if 'cxxflags' in values:
            self.cxxflags += [values['cxxflags']]
        if 'ldflags' in values:
            self.ldflags += [values['ldflags']]

        if 'libs' in values:
            self.libs = values['libs'].split() + self.libs

        if 'static_libs' in values:
            self.static_libs = values['static_libs'].split() + self.static_libs

        if 'c_std' in values:
            self.c_std = values['c_std']
        if 'cxx_std' in values:
            self.cxx_std = values['cxx_std']

        if 'src_c' in values:
            self.src_c += expand(entry.dir, values['src_c'])
        if 'src_cpp' in values:
            self.src_cpp += expand(entry.dir, values['src_cpp'])

    def load_requirements(self, build_info):
        requires = self.target_entry.requires

        if self.target_entry.gpu:
            self.load_entry(build_info.gpu_entry)
            self.gpu_backend_entry = build_info.get_gpu_backend_entry(self.target_entry.gpu_backend)
            requires += self.gpu_backend_entry.requires
            self.load_entry(self.gpu_backend_entry)
            self.headers += [build_info.gpu_src_dir]
            self.headers += [self.gpu_backend_entry.dir]
            self.headers += [self.build_dir]
            # TODO backend path
            self.headers += [self.build_dir.joinpath(GPU_DIR).joinpath(GPU_BACKENDS_DIR).joinpath(self.gpu_backend_entry.name)]

            if self.target_entry.gpu_assets_builtin:
                #print('toto')
                pass

            self.rules += []

        requires = set(requires)
        for r in requires:
            module = importlib.import_module('.deps.' + r.requires, 'pymk')
            if hasattr(module, 'target'):
                func = getattr(module, 'target')
                func(self, r.entry, build_info)
