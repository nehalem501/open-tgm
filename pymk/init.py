#!/usr/bin/env python3

import re

def sed_inplace(input, output, pattern, repl):
    pattern_compiled = re.compile(pattern)

    with open(output, mode='x') as out_file:
        with open(input, mode='r') as src_file:
            for line in src_file:
                out_file.write(pattern_compiled.sub(repl, line))


def init_platform(name):
    pass

def init_gpu_platform(name):
    pass

def init_gpu_backend(name):
    pass
