#!/usr/bin/env python3

import os
import pipes

from . import ninja_syntax

BUILD_FILENAME = 'build.ninja'

def run(target, debug, build_info):
    n = ninja_syntax.Writer(open(BUILD_FILENAME, 'w'))

    n.comment('This file is used to build Open TGM')
    n.comment('Target: ' + target.name)
    n.newline()

    n.variable('ninja_required_version', '1.3')
    n.newline()

    #env_keys = set([
    #    'AS', 'CC', 'CXX', 'ASFLAGS', 'CFLAGS', 'CXXFLAGS', 'LDFLAGS',
    #    'HOST_CC', 'HOST_CXX', 'HOST_CFLAGS', 'HOST_CXXFLAGS', 'HOST_LDFLAGS'])
    #configure_env = dict((k, os.environ[k]) for k in os.environ if k in env_keys)
    #if configure_env:
    #    config_str = ' '.join([k + '=' + pipes.quote(configure_env[k])
    #                        for k in configure_env])
    #    n.variable('configure_env', config_str + '$ ')
    #n.newline()

    # Compilers
    n.variable('cc', target.cc)
    n.variable('cxx', target.cxx)
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

    n.rule('ld',
        command='$ld $cxxflags $ldflags -o $out $in $libs',
        description='$ld $out')
    n.newline()

    n.comment('C sources')
    for s in target.src_c:
        n.build(s.output, 'cc', s.input)
    n.newline()

    n.comment('CPP sources')
    for s in target.src_cpp:
        n.build(s.output, 'cxx', s.input)
    n.newline()

    #n.build('output.o', 'cc', 'input.c')
