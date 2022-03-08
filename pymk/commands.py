#!/usr/bin/env python3

from .build import build_target
from .clean import clean_target
from . import globals

class Options:
    def __init__(self, debug, verbose, jobs):
        self.debug = debug
        self.verbose = verbose
        self.jobs = jobs

def build(args):
    debug = False if args.release else True
    options = Options(debug, args.verbose, args.jobs)
    targets = args.targets
    if isinstance(targets, str):
        targets = [args.targets]
    if 'all' in targets:
        targets = globals.BUILD_INFO.platforms # TODO handle special targets such as SDL
    for t in targets:
        build_target(t, options, globals.BUILD_INFO)

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
    options = Options(debug, args.verbose, args.jobs)
    build_target(args.target, options, globals.BUILD_INFO)
    # TODO launch
    pass

def test(args):
    pass

def init(args):
    pass
