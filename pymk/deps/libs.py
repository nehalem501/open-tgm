#!/usr/bin/env python3

from collections import namedtuple

def decode_libs(entry):
    items = entry.split()
    tuple = namedtuple('Tuple', ['libs', 'ldflags'])
    tuple.libs = []
    tuple.ldflags = []
    for i in items:
        if i.startswith('-l'):
            tuple.libs += [i[2:]]
        else:
            tuple.ldflags += [i]
    return tuple
