#!/usr/bin/env python3

from pathlib import Path
from .expand import expand
from .rule import to_src_rule, Rule, Build

def target(self, entry, build_info):
    self.rules += [Rule('picasso', 'picasso -o $out $in', 'compile shader $out')]
    shaders = expand(entry.dir, entry.values['src_shader'])
    shaders_bin = [to_src_rule(build_info.root_dir, build_info.src_dir, self.build_dir, s, '.shbin') for s in shaders]
    for s in shaders_bin:
        self.builds += [Build(s.output, 'picasso', s.input)]
        self.builtin_data += [Path(s.output)]
