#!/usr/bin/env python3

# Open TGM build

import argparse
import pymk.commands as cmd
import pymk.globals as globals

from pathlib import Path
from pymk.build import BuildInfo

# Parse build.ini files
globals.BUILD_INFO = BuildInfo(Path(__file__).parent)
BUILD_INFO = globals.BUILD_INFO

# Common variables
default_target = BUILD_INFO.default_target
build_targets = ['', 'all'] + BUILD_INFO.platforms
run_targets = [''] + BUILD_INFO.platforms

parser = argparse.ArgumentParser(description='Open TGM build')
parser.add_argument('-v', '--verbose', action='store_true', help='show all command lines while building')
parser.add_argument('-j', '--jobs', metavar='N', help='run N jobs in parallel')

subparsers = parser.add_subparsers(title='subcommands')

parser_build = subparsers.add_parser('build', aliases=['b'], help='compile project')
build_mode = parser_build.add_mutually_exclusive_group()
build_mode.add_argument('--debug', action='store_true')
build_mode.add_argument('--release', action='store_true')
parser_build.add_argument('targets', nargs='*', choices=build_targets, default=default_target)
parser_build.set_defaults(func=cmd.build)

parser_clean = subparsers.add_parser('clean', aliases=['c'], help='remove generated files')
parser_clean.add_argument('targets', nargs='*', choices=build_targets, default=default_target)
parser_clean.set_defaults(func=cmd.clean)

parser_run = subparsers.add_parser('run', aliases=['r'], help='run program')
run_mode = parser_run.add_mutually_exclusive_group()
run_mode.add_argument('--debug', action='store_true')
run_mode.add_argument('--release', action='store_true')
parser_run.add_argument('target', nargs='?', choices=run_targets, default=default_target)
parser_run.set_defaults(func=cmd.run)

parser_test = subparsers.add_parser('test', aliases=['t'], help='run unit tests')
parser_test.set_defaults(func=cmd.test)

parser_init = subparsers.add_parser('init', aliases=['i'], help='create and init port to new platform')
init_mode = parser_init.add_mutually_exclusive_group(required=True)
init_mode.add_argument('--platform', action='store_true')
init_mode.add_argument('--gpu-backend', action='store_true')
init_mode.add_argument('--gpu-platform', action='store_true')
parser_init.add_argument('name')
parser_init.set_defaults(func=cmd.init)

parser.set_defaults(func=lambda args: parser.print_help())

args = parser.parse_args()
args.func(args)
