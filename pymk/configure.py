#!/usr/bin/env python3

import sys
from .deps.rule import Variable, Rule, Build
from .ninja import NinjaBuild
from .globals import TOOLS_DIR
from . import globals

def run(target, prefix, file):
    BUILD_INFO = globals.BUILD_INFO

    variables = [
        Variable('cc', target.cc),
        Variable('cxx', target.cxx),
        Variable('link', target.link),
        Variable('cflags', target.cflags),
        Variable('cxxflags', target.cxxflags),
        Variable('ldflags', target.ldflags),
        Variable('libs', target.libs)
    ]

    variables += target.variables

    rules = [
        Rule('cc',
            command='$cc -MMD -MT $out -MF $out.d $cflags -c $in -o $out',
            depfile='$out.d',
            deps='gcc',
            description='$cc $out'),
        Rule('cxx',
            command='$cxx -MMD -MT $out -MF $out.d $cxxflags -c $in -o $out',
            depfile='$out.d',
            deps='gcc',
            description='$cxx $out'),
        Rule('link',
            command='$link $cxxflags $ldflags -o $out $in $libs',
            description='$link $out')
    ]

    rules += target.rules

    if target.builtin_data:
        script = BUILD_INFO.scripts_dir.joinpath('bin2cpp.py')
        bin2cpp = f'{sys.executable} {script}'
        rules += [
            Rule('bin2cpp',
                command=f'{bin2cpp} -i $in -o $out',
                description='generate $out')
        ]

    if target.textures:
        img2tx = BUILD_INFO.build_dir.joinpath(TOOLS_DIR).joinpath('img2tx').joinpath('img2tx')
        rules += [
            Rule('img2tx',
                command=f'{img2tx} $in $out',
                description='convert $out')
        ]

    if target.data_headers:
        script = BUILD_INFO.scripts_dir.joinpath('convert.py')
        convert = f'{sys.executable} {script}'
        rules += [
            Rule('convert',
                command=f'{convert} -i $in -o $out -n $name',
                description='convert $out')
        ]

    builds = []

    dependencies = []
    for d in target.builtin_data:
        dependencies += [d.output_header]
        builds += [
            Build(d.output_cpp, 'bin2cpp', d.input, implicit_outputs=d.output_header),
            Build(d.output_object, 'cxx', d.output_cpp)
        ]

    for t in target.textures:
        builds += [
            Build(t.output, 'img2tx', t.input),
        ]

    for d in target.data_headers:
        dependencies += [d.output]
        builds += [
            Build(d.output, 'convert', d.input, variables={'name': d.name}),
        ]

    builds += [Build(s.output, 'cc', s.input) for s in target.src_c]
    builds += [Build(s.output, 'cxx', s.input, dependencies=dependencies) for s in target.src_cpp]

    builds += [Build(target.binary, 'link', target.objects)]

    builds += target.builds

    return NinjaBuild(file, variables, rules, builds, path=target.get_path())
