#!/usr/bin/env python3

import importlib
import os
import platform
import subprocess

from pathlib import Path
from . import globals
from .entry import BuildEntry
from .globals import GPU_DIR, GPU_BACKENDS_DIR, DATA_DIR, RESOURCES_DIR, LIBS_DIR
from .deps.expand import expand, get_path
from .deps.requirement import Requirement
from .deps.rule import to_src_rule, to_data_rule, to_texture_rule

def headers_to_flags(headers):
    return ['-I' + str(h) for h in headers]

def libs_to_flags(libs):
    return ['-l' + str(l) for l in libs]

def lib_dirs_to_flags(lib_dirs):
    return ['-L' + str(l) for l in lib_dirs]

class TargetData:
    def __init__(self, entry, additional_entries, options, build_dir, binary, library, common_flags, headers):
        self.entry = entry
        self.additional_entries = additional_entries
        self.options = options
        self.build_dir = build_dir
        self.binary = binary
        self.library = library
        self.common_flags = common_flags
        self.headers = headers

class Target:
    def __init__(self, data):
        BUILD_INFO = globals.BUILD_INFO

        self.cc = 'cc'
        self.cxx = 'c++'
        self.link = None

        self.c_std = 'c99'
        self.cxx_std = 'c++11'

        self.asflags = []
        self.cflags = []
        self.cxxflags = []
        self.ldflags = []

        self.libs = []
        self.static_libs = []
        self.lib_dirs = []
        self.tools = []

        self.src_c = []
        self.src_cpp = []

        self.builtin_data = []
        self.shaders = []
        self.textures = []

        self.objects = []
        self.binary = data.binary
        self.library = data.library

        self.path = []
        self.rules = []
        self.builds = []
        self.variables = []

        self.requirement_options = dict()
        self.requires = []

        self.build_dir = data.build_dir
        #self.build_file = build_info.root_dir.joinpath(target).with_suffix('.ninja')
        self.header_list_path = data.build_dir.joinpath(DATA_DIR).joinpath('data_info.h')
        self.textures_list_path = data.build_dir.joinpath(DATA_DIR).joinpath('textures_info.h')
        self.shaders_list_path = data.build_dir.joinpath(DATA_DIR).joinpath('shaders_info.h')

        self.cflags += data.common_flags
        self.cxxflags += data.common_flags

        self.headers = data.headers

        self.load_entry(data.entry)
        for e in data.additional_entries:
            self.load_entry(e)

        self.load_requirements(BUILD_INFO, data.additional_entries)

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
            self.shaders = [to_data_rule(BUILD_INFO.root_dir, self.build_dir, s) for s in self.shaders]
            pass

        self.builtin_data += self.shaders

        #for r in self.builtin_data:
        #    self.src_cpp += [Path(r.output_cpp)]

        if self.binary is not None:
            self.binary = str(self.binary)
        if self.library is not None:
            self.library = str(self.library)
            if os.name == 'nt':
                self.ldflags += [''] # TODO
            else:
                if platform.system() == 'Darwin':
                    self.ldflags += ['-dynamiclib', '-fPIC']
                else:
                    self.ldflags += ['-shared', '-fPIC']

        self.src_c = [to_src_rule(BUILD_INFO.root_dir, BUILD_INFO.src_dir, self.build_dir, s, '.o') for s in self.src_c]
        self.src_cpp = [to_src_rule(BUILD_INFO.root_dir, BUILD_INFO.src_dir, self.build_dir, s, '.o') for s in self.src_cpp]

        self.objects += [r.output for r in self.src_c] + [r.output for r in self.src_cpp]
        for r in self.builtin_data:
            self.objects += [r.output_object]

        self.header_list_path = str(self.header_list_path)
        self.textures_list_path = str(self.textures_list_path)
        self.shaders_list_path = str(self.shaders_list_path)

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
                my_env["PATH"] = get_path(self.path) + my_env["PATH"]

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

    def load_entry(self, entry):
        values = entry.values

        if 'binary' in values and self.binary is not None:
            new_binary = values['binary']
            if self.binary.stem != new_binary:
                self.binary = self.binary.with_name(new_binary)

        if 'library' in values and self.library is not None:
            new_library = values['library']
            if self.library.stem != new_library:
                self.library = self.library.with_name(new_library)

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

        if 'headers' in values:
            self.headers += values['headers'].split()

        if 'libs' in values:
            self.libs = values['libs'].split() + self.libs

        if 'static_libs' in values:
            self.static_libs = values['static_libs'].split() + self.static_libs

        if 'tools' in values:
            self.tools += values['tools'].split()

        if 'c_std' in values:
            self.c_std = values['c_std']
        if 'cxx_std' in values:
            self.cxx_std = values['cxx_std']

        if 'src_c' in values:
            self.src_c += expand(entry.dir, values['src_c'])
        if 'src_cpp' in values:
            self.src_cpp += expand(entry.dir, values['src_cpp'])

        if 'requires' in values:
            self.requires += [Requirement(entry, r) for r in values['requires'].split()]

        # TODO handle options in a generic way
        if 'zstd' in values:
            self.requirement_options['zstd'] = (values['zstd'] == 'compress')

    def load_requirement(self, requirement, entry, options):
            module = importlib.import_module('.deps.' + requirement, 'pymk')
            if hasattr(module, 'target'):
                func = getattr(module, 'target')
                func(self, entry, options, globals.BUILD_INFO)

    def load_requirements(self, build_info, entries):
        requires = set(self.requires)
        for e in entries:
            if hasattr(e, 'gpu') and e.gpu:
                entry = e
                self.load_entry(build_info.gpu_entry)
                self.gpu_backend_entry = build_info.get_gpu_backend_entry(entry.gpu_backend)
                self.load_entry(self.gpu_backend_entry)
                self.headers += [build_info.gpu_src_dir]
                self.headers += [self.gpu_backend_entry.dir]
                self.headers += [self.build_dir]
                # TODO backend path
                self.headers += [self.build_dir.joinpath(GPU_DIR).joinpath(GPU_BACKENDS_DIR).joinpath(self.gpu_backend_entry.name)]

                resources_dir = build_info.root_dir.joinpath(DATA_DIR).joinpath(RESOURCES_DIR)
                ini_files = []
                for size in entry.gpu_tile_sizes:
                    dir = resources_dir.joinpath(size)
                    ini_files += expand(dir, '*.ini')

                png_files = [(i, i.with_suffix('.png')) for i in ini_files]

                #self.textures = [to_data_rule(self.root_dir, self.build_dir, f) for f in png_files]

                if entry.gpu_assets_builtin:
                    # we need also to take care of data_info and other headers generation
                    self.textures = [to_texture_rule(build_info.root_dir, build_info.data_dir, self.build_dir, f[0], f[1]) for f in png_files]
                    for t in self.textures:
                        rule = to_data_rule(build_info.root_dir, self.build_dir, Path(t.output))
                        t.output_header = rule.output_header
                        self.builtin_data += [rule]
                else:
                    # create copy target, asset detection and loading should happen at runtime
                    pass
                    #self.textures = [to_src_rule_keep_suffix(build_info.root_dir, build_info.root_dir, self.build_dir, t, '.cpp') for t in self.textures]

        if self.static_libs:
            libs_dir = build_info.src_dir.joinpath(LIBS_DIR)
            #static_libs_entries = []
            for l in self.static_libs:
                entry = BuildEntry(libs_dir.joinpath(l))
                self.load_entry(entry)
                self.headers += [entry.dir]

        requires = set(self.requires)
        for r in requires:
            self.load_requirement(r.requires, r.entry, self.requirement_options)