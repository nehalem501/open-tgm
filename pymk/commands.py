#!/usr/bin/env python3

from .build import build_target
from .clean import clean_target
from . import globals

def build(args):
    debug = False if args.release else True
    targets = args.targets
    if isinstance(targets, str):
        targets = [args.targets]
    if 'all' in targets:
        targets = globals.BUILD_INFO.platforms # TODO handle special targets such as SDL
    for t in targets:
        build_target(t, debug, globals.BUILD_INFO)

def clean(args):
    targets = args.targets
    if isinstance(targets, str):
        targets = [args.targets]
    if 'all' in targets:
        targets = globals.BUILD_INFO.platforms # TODO handle special targets such as SDL
    for t in targets:
        clean_target(t)

def run(args):
    debug = False if args.release else True
    build_target(args.target, debug, globals.BUILD_INFO)
    # TODO launch
    pass

def test():
    pass
