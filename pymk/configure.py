#!/usr/bin/env python3

import os
import sys
import subprocess
from pathlib import Path
from . import ninja_syntax

def run(target, options, build_info):
    n = ninja_syntax.Writer(open(target.build_file, 'w'))

    n.comment('This file is used to build Open TGM')
    n.comment('Target: ' + target.name)
    n.newline()

    n.variable('ninja_required_version', '1.7')
    n.newline()

    # Compilers
    n.variable('cc', target.cc)
    n.variable('cxx', target.cxx)
    n.variable('link', target.link)
    n.newline()

    # Flags
    n.variable('cflags', target.cflags)
    n.variable('cxxflags', target.cxxflags)
    n.newline()

    n.rule('cc',
        command='$cc -MMD -MT $out -MF $out.d $cflags -c $in -o $out',
        depfile='$out.d',
        deps='gcc',
        description='$cc $out')
    n.newline()

    n.rule('cxx',
        command='$cxx -MMD -MT $out -MF $out.d $cxxflags -c $in -o $out',
        depfile='$out.d',
        deps='gcc',
        description='$cxx $out')
    n.newline()

    n.rule('link',
        command='$link $cxxflags $ldflags -o $out $in $libs',
        description='$link $out')
    n.newline()

    if target.builtin_data:
        script = target.scripts_dir.joinpath('bin2cpp.py')
        bin2cpp = f'{sys.executable} {script}'
        n.rule('bin2cpp',
            command=f'{bin2cpp} -i $in -o $out',
            description='generate $out')
        n.newline()

    for r in target.rules:
        n.rule(r.name, command=r.command, description=r.description)
        n.newline()

    n.comment('C sources')
    for s in target.src_c:
        n.build(s.output, 'cc', s.input)
    n.newline()

    n.comment('CPP sources')
    for s in target.src_cpp:
        n.build(s.output, 'cxx', s.input)
    n.newline()

    n.build(target.binary, 'link', target.objects)
    n.newline()

    for b in target.builds:
        n.build(b.outputs, b.rule, b.inputs)
        n.newline()

    for d in target.builtin_data:
        input = d.input
        cpp = d.output
        header = str(Path(d.output).with_suffix('.h'))
        object = str(Path(d.output).with_suffix('.o'))
        n.build(cpp, 'bin2cpp', input, implicit_outputs=header)
        n.newline()
        n.build(object, 'cxx', cpp)
        n.newline()

    n.close()

    my_env = os.environ.copy()
    if target.path:
        my_env["PATH"] = target.get_path() + my_env["PATH"]

    cmd = ['ninja']
    if options.verbose:
        cmd += ['-v']
    cmd += ['-f', target.build_file]

    proc = subprocess.Popen(cmd, env=my_env)
    proc.wait()
    if proc.returncode != 0:
        exit(proc.returncode)
