#!/usr/bin/env python3

import importlib
import os
import subprocess
import sys

from pathlib import Path
from .globals import GPU_DIR, GPU_BACKENDS_DIR
from .deps.expand import expand
from .deps.rule import Rule, Build, to_src_rule, to_src_rule_keep_suffix

def headers_to_flags(headers):
    return ['-I' + str(h) for h in headers]

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

    def __init__(self, target, options, build_info):
        self.name = target

        self.build_dir = build_info.get_target_build_dir(target)
        self.root_dir = build_info.root_dir
        self.scripts_dir = build_info.root_dir.joinpath('pymk')
        self.binary = str(build_info.get_target_bin_dir(target).joinpath(self.name))
        self.build_file = build_info.root_dir.joinpath(target).with_suffix('.ninja')

        if 'name' in build_info.toplevel.values:
            self.name = build_info.toplevel.values['name']

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

        self.cflags += headers_to_flags(self.headers)
        self.cxxflags += headers_to_flags(self.headers)

        self.cflags += ['-std=' + self.c_std]
        self.cxxflags += ['-std=' + self.cxx_std]

        if self.link is None:
            self.link = self.cxx

        #if self.builtin_data:
        #    self.builtin_data = [to_src_rule_keep_suffix(build_info.root_dir, build_info.root_dir, self.build_dir, s, '.cpp') for s in self.builtin_data]

        if self.shaders:
            # shaders are always builtin
            self.shaders = [to_src_rule_keep_suffix(build_info.root_dir, build_info.root_dir, self.build_dir, s, '.cpp') for s in self.shaders]
            pass

        if self.textures:
            if self.target_entry.gpu_assets_builtin:
                # assets objects should be built in build_dir/data/_px
                # we need also to take care of data_info and other headers generation
                pass
            else:
                # create copy target, asset detection and loading should happen at runtime
                pass
            #self.textures = [to_src_rule_keep_suffix(build_info.root_dir, build_info.root_dir, self.build_dir, t, '.cpp') for t in self.textures]

        self.builtin_data += self.shaders + self.textures

        for r in self.builtin_data:
            self.src_cpp += [Path(r.output)]

        self.src_c = [to_src_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s, '.o') for s in self.src_c]
        self.src_cpp = [to_src_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s, '.o') for s in self.src_cpp]

        self.objects += [r.output for r in self.src_c] + [r.output for r in self.src_cpp]


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
