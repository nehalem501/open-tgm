#!/usr/bin/env python3

import sys
from .deps.rule import Variable, Rule, Build
from .ninja import NinjaBuild
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
    ]

    if target.binary is not None:
        rules += [
            Rule('link',
                command='$link $cxxflags $ldflags -o $out $in $libs',
                description='$link $out')
        ]

    if target.library is not None:
        rules += [
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
        script = BUILD_INFO.scripts_dir.joinpath('list.py')
        list = f'{sys.executable} {script}'
        rules += [
            Rule('list',
                command=f'{list} -o $out $in',
                description='generate $out'),
            Rule('list_header_only',
                command=f'{list} --includes-only -o $out $in',
                description='generate $out')
        ]

    if target.textures:
        script = BUILD_INFO.scripts_dir.joinpath('img2tx.py')
        img2tx = f'{sys.executable} {script}'
        rules += [
            Rule('img2tx',
                command=f'{img2tx} -i $in -m $ini_file -o $out',
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

    if target.builtin_data:
        headers = [target.textures_list_path]
        if target.shaders:
            headers += [target.shaders_list_path]
        output = target.header_list_path
        dependencies += [output]
        builds += [
            Build(output, 'list_header_only', headers)
        ]

    for t in target.textures:
        builds += [
            Build(t.output, 'img2tx', t.png, variables={'ini_file': t.ini}),
        ]
    if target.shaders:
        headers = [s.output_header for s in target.shaders]
        output = target.shaders_list_path
        dependencies += [output]
        builds += [
            Build(output, 'list', headers)
        ]

    if target.textures:
        headers = [t.output_header for t in target.textures]
        output = target.textures_list_path
        dependencies += [output]
        builds += [
            Build(output, 'list', headers)
        ]

    builds += [Build(s.output, 'cc', s.input) for s in target.src_c]
    builds += [Build(s.output, 'cxx', s.input, dependencies=dependencies) for s in target.src_cpp]

    if target.binary is not None:
        builds += [Build(target.binary, 'link', target.objects)]

    if target.library is not None:
        builds += [Build(target.library, 'link', target.objects)]

    builds += target.builds

    return NinjaBuild(file, variables, rules, builds, path=target.get_path())
