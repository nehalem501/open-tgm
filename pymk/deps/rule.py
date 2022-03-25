#!/usr/bin/env python3

from os import name


class Rule:
    def __init__(self, name, command, description, depfile=None, deps=None):
        self.name = name
        self.command = command
        self.description = description
        self.depfile = depfile
        self.deps = deps

class Build:
    def __init__(self, outputs, rule, inputs, dependencies=None, implicit_outputs=None, variables=None):
        self.outputs = outputs
        self.rule = rule
        self.inputs = inputs
        self.dependencies = dependencies
        self.implicit_outputs = implicit_outputs
        self.variables = variables

class Variable:
    def __init__(self, name, value):
        self.name = name
        self.value = value

class SrcRule:
    def __init__(self, output, input):
        self.output = str(output)
        self.input = str(input)

    def __repr__ (self):
        return f"SrcRule('{self.output}' ⇐ '{self.input}')"

class TextureRule:
    def __init__(self, output, ini, png):
        self.output = str(output)
        self.ini = str(ini)
        self.png = str(png)

class DataHeaderRule:
    def __init__(self, output, input, name):
        self.output = str(output)
        self.input = str(input)
        self.name = str(name)

class DataRule:
    def __init__(self, output_header, output_cpp, output_object, input):
        self.output_header = str(output_header)
        self.output_cpp = str(output_cpp)
        self.output_object = str(output_object)
        self.input = str(input)

"""
class SrcRuleN:
    def __init__(self, outputs, input):
        self.outputs = [str(o) for o in outputs]
        self.input = str(input)
"""

def to_src_rule(root_dir, source_dir, build_dir, source, suffix):
    source_dir_rel = source_dir.relative_to(root_dir)
    source_rel = source.relative_to(root_dir).relative_to(source_dir_rel)
    build_dir_rel = build_dir.relative_to(root_dir)
    filename = root_dir.joinpath(build_dir_rel).joinpath(source_rel)
    while filename.suffix:
        filename = filename.with_suffix('')
    object = filename.with_suffix(suffix)
    return SrcRule(object, source)

def to_texture_rule(root_dir, source_dir, build_dir, ini, png):
    suffix = '.txf'
    source_dir_rel = source_dir.relative_to(root_dir)
    source_rel = png.relative_to(root_dir).relative_to(source_dir_rel)
    build_dir_rel = build_dir.relative_to(root_dir)
    filename = root_dir.joinpath(build_dir_rel).joinpath(source_rel)
    while filename.suffix:
        filename = filename.with_suffix('')
    size = filename.parent.name
    output = filename.with_suffix('.' + size + suffix)
    return TextureRule(output, ini, png)

def to_data_rule(root_dir, build_dir, file):
    file_rel = file.relative_to(root_dir)
    filename = root_dir.joinpath(file_rel) if is_relative_to(file, build_dir) else build_dir.joinpath(file_rel)
    header = filename.with_suffix(filename.suffix + '.h')
    cpp = filename.with_suffix(filename.suffix + '.cpp')
    object = filename.with_suffix(filename.suffix + '.o')
    return DataRule(header, cpp, object, file)

"""
def to_src_rule_n(root_dir, source_dir, build_dir, source, suffixes):
    source_rel = source.relative_to(source_dir)
    build_dir_rel = build_dir.relative_to(root_dir)
    filename = root_dir.joinpath(build_dir_rel).joinpath(source_rel)
    while filename.suffix:
        filename = filename.with_suffix('')
    outputs = [filename.with_suffix(s) for s in suffixes]
    return SrcRuleN(outputs, source)
"""

def is_relative_to(path, *other):
    """Return True if the path is relative to another path or False.
    """
    try:
        path.relative_to(*other)
        return True
    except ValueError:
        return False
