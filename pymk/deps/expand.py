#!/usr/bin/env python3

def expand(dir, entry):
    items = entry.split()
    files = []
    for i in items:
        files += dir.glob(i)
    return files

def get_path(path):
    return ':'.join([str(p) for p in path]) + ':'

class SourceWithFlags:
    def __init__(self, source, flags):
        self.source = source
        self.flags = flags

def to_sources(sources, cflags_override=[]):
    return [SourceWithFlags(src, cflags_override) for src in sources]
