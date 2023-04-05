#!/usr/bin/env python3

from .expand import expand, to_sources

def target(self, entry, options, build_info):
    if options['zstd']:
        self.cflags += [entry.values['cflags_compress']]
        self.src_c += to_sources(expand(entry.dir, entry.values['src_c_compress']))
    else:
        self.cflags += [entry.values['cflags_decompress']]
        self.src_c += to_sources(expand(entry.dir, entry.values['src_c_decompress']))
