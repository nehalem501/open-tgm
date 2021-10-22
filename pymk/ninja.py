#!/usr/bin/env python3

import os
import sys
import subprocess
from . import ninja_syntax
#from . import globals

class NinjaBuild:
    def __init__(self, file, variables, rules, builds, path=None):
        self.file = file
        self.variables = variables
        self.rules = rules
        self.builds = builds
        self.path = path

def run(build, options):
    #BUILD_INFO = globals.BUILD_INFO

    n = ninja_syntax.Writer(open(build.file, 'w'))

    n.comment('This file is used to build Open TGM')
    #n.comment('Target: ' + target.name)
    n.newline()

    n.variable('ninja_required_version', '1.7')
    n.newline()

    # Compilers
    #n.variable('cc', target.cc)
    #n.variable('cxx', target.cxx)
    #n.variable('link', target.link)
    #n.newline()

    # Flags
    #n.variable('cflags', target.cflags)
    #n.variable('cxxflags', target.cxxflags)
    #n.variable('ldflags', target.ldflags)
    #n.newline()
    #n.variable('libs', target.libs)
    #n.newline()

    for v in build.variables:
        n.variable(v.name, v.value)
        n.newline()

    n.newline()

    #n.rule('cc',
    #    command='$cc -MMD -MT $out -MF $out.d $cflags -c $in -o $out',
    #    depfile='$out.d',
    #    deps='gcc',
    #    description='$cc $out')
    #n.newline()

    #n.rule('cxx',
    #    command='$cxx -MMD -MT $out -MF $out.d $cxxflags -c $in -o $out',
    #    depfile='$out.d',
    #    deps='gcc',
    #    description='$cxx $out')
    #n.newline()

    #n.rule('link',
    #    command='$link $cxxflags $ldflags -o $out $in $libs',
    #    description='$link $out')
    #n.newline()

    for r in build.rules:
        n.rule(r.name, command=r.command, description=r.description, depfile=r.depfile, deps=r.deps)
        n.newline()

    #if target.builtin_data:
    #    script = BUILD_INFO.scripts_dir.joinpath('bin2cpp.py')
    #    bin2cpp = f'{sys.executable} {script}'
    #    n.rule('bin2cpp',
    #        command=f'{bin2cpp} -i $in -o $out',
    #        description='generate $out')
    #    n.newline()

    #dependencies = []
    #n.comment('builtin data')
    #for d in target.builtin_data:
    #    dependencies += [d.output_header]
    #    n.build(d.output_cpp, 'bin2cpp', d.input, implicit_outputs=d.output_header)
    #    n.newline()
    #    n.build(d.output_object, 'cxx', d.output_cpp)
    #    n.newline()

    #n.comment('C sources')
    #for s in target.src_c:
    #    n.build(s.output, 'cc', s.input)
    #n.newline()

    #n.comment('CPP sources')
    #for s in target.src_cpp:
    #    n.build(s.output, 'cxx', s.input, implicit=dependencies)
    #n.newline()

    #n.build(target.binary, 'link', target.objects)
    #n.newline()

    for b in build.builds:
        n.build(b.outputs, b.rule, b.inputs, implicit=b.dependencies, implicit_outputs=b.implicit_outputs)
        n.newline()

    n.close()

    my_env = os.environ.copy()
    if build.path is not None and build.path:
        my_env["PATH"] = build.path + my_env["PATH"]
        # TODO
        #my_env["PATH"] = target.get_path() + my_env["PATH"]

    cmd = ['ninja']
    if options.verbose:
        cmd += ['-v']
    if options.jobs:
        cmd += ['-j', str(options.jobs)]
    cmd += ['-f', build.file]

    proc = subprocess.Popen(cmd, env=my_env)
    proc.wait()
    if proc.returncode != 0:
        exit(proc.returncode)
