#!/usr/bin/env python3

class Rule:
    def __init__(self, name, command, description):
        self.name = name
        self.command = command
        self.description = description

class Build:
    def __init__(self, outputs, rule, inputs):
        self.outputs = outputs
        self.rule = rule
        self.inputs = inputs

class SrcRule:
    def __init__(self, output, input):
        self.output = str(output)
        self.input = str(input)

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

def to_data_rule(root_dir, build_dir, file):
    file_rel = file.relative_to(root_dir)
    filename = root_dir.joinpath(file_rel) if file.is_relative_to(build_dir) else build_dir.joinpath(file_rel)
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
