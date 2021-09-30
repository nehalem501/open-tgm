#!/usr/bin/env python3

def expand(dir, entry):
    items = entry.split()
    files = []
    for i in items:
        files += dir.glob(i)
    return files
