#!/usr/bin/env python3

from os import chflags

def expand(dir, entry):
    items = entry.split()
    files = []
    for i in items:
        files += dir.glob(i)
    return files

class Rule:
    def __init__(self, output, input):
        self.output = str(output)
        self.input = str(input)

def to_rule(root_dir, source_dir, build_dir, source):
    source_dir_rel = source_dir.relative_to(root_dir)
    source_rel = source.relative_to(source_dir)
    build_dir_rel = build_dir.relative_to(root_dir)
    object = root_dir.joinpath(build_dir_rel).joinpath(source_rel).with_suffix('.o')
    return Rule(object, source)

def headers_to_flags(headers):
    return ['-I' + str(h) for h in headers]

class Target:
    cc = 'cc'
    cxx = 'c++'
    ld = cxx

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

    binary = 'a.out'

    def __init__(self, target, debug, build_info):
        self.name = target

        if 'name' in build_info.toplevel.values:
            self.name = build_info.toplevel.values['name']

        if 'c_std' in build_info.toplevel.values: #TODO target override
            self.c_std = build_info.toplevel.values['c_std']

        if 'cxx_std' in build_info.toplevel.values: #TODO target override
            self.cxx_std = build_info.toplevel.values['cxx_std']

        self.headers += [build_info.core_headers_dir]
        self.headers += [build_info.platforms_dir.joinpath(target)]

        common_flags = []
        if debug:
            common_flags += [build_info.toplevel.values['debug_flags']]
        else:
            common_flags += ['-O2'] # TODO optimisation levels and types

        common_flags += [build_info.toplevel.values['common_flags']]
        common_flags += ['-DTARGET_' + target.upper()]
        common_flags += headers_to_flags(self.headers)

        self.cflags += common_flags + ['-std=' + self.c_std]
        self.cxxflags += common_flags + ['-std=' + self.cxx_std]

        src_c = []
        src_cpp = []

        for e in build_info.core_entries:
            if 'src_c' in e.values:
                src_c += expand(e.dir, e.values['src_c'])
            if 'src_cpp' in e.values:
                src_cpp += expand(e.dir, e.values['src_cpp'])

        target_entry = build_info.get_platform_entry(target)
        values = target_entry.values

        if 'cc' in values:
            self.cc = values['cc']

        if 'cxx' in values:
            self.cxx = values['cxx']

        if 'ld' in values:
            self.ld = values['ld']
        else:
            self.ld = self.cxx

        if 'cflags' in values:
            self.cflags += [values['cflags']]

        if 'cxxflags' in values:
            self.cxxflags += [values['cxxflags']]

        if 'ldflags' in values:
            self.ldflags += [values['ldflags']]

        self.build_dir = build_info.get_target_build_dir(target)

        self.src_c = [to_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s) for s in src_c]
        self.src_cpp = [to_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s) for s in src_cpp]
