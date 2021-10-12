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

class SrcRuleN:
    def __init__(self, outputs, input):
        self.outputs = [str(o) for o in outputs]
        self.input = str(input)

def to_src_rule(root_dir, source_dir, build_dir, source, suffix):
    source_rel = source.relative_to(root_dir)
    build_dir_rel = build_dir.relative_to(root_dir)
    filename = root_dir.joinpath(build_dir_rel).joinpath(source_rel)
    while filename.suffix:
        filename = filename.with_suffix('')
    object = filename.with_suffix(suffix)
    return SrcRule(object, source)

def to_src_rule_keep_suffix(root_dir, source_dir, build_dir, source, suffix):
    source_rel = source.relative_to(source_dir)
    #build_dir_rel = build_dir.relative_to(root_dir)
    filename = root_dir.joinpath(source_rel)
    object = filename.with_suffix(filename.suffix + suffix)
    return SrcRule(object, source)

def to_src_rule_n(root_dir, source_dir, build_dir, source, suffixes):
    source_rel = source.relative_to(source_dir)
    build_dir_rel = build_dir.relative_to(root_dir)
    filename = root_dir.joinpath(build_dir_rel).joinpath(source_rel)
    while filename.suffix:
        filename = filename.with_suffix('')
    outputs = [filename.with_suffix(s) for s in suffixes]
    return SrcRuleN(outputs, source)
