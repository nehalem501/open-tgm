#!/usr/bin/env python3

# Open TGM build

import argparse
import pymk.commands as cmd
import pymk.globals as globals

from pathlib import Path
from pymk.build import BuildInfo

# Parse build.ini files
globals.PROJECT_ROOT = Path(__file__).parent.absolute()
globals.BUILD_INFO = BuildInfo(globals.PROJECT_ROOT)
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
test_mode = parser_test.add_mutually_exclusive_group()
test_mode.add_argument('--debug', action='store_true')
test_mode.add_argument('--release', action='store_true')
parser_test.set_defaults(func=cmd.test)

parser_init = subparsers.add_parser('init', aliases=['i'], help='create and init port to new platform')
subparsers_init = parser_init.add_subparsers()

parser_init_platform = subparsers_init.add_parser('platform', help='new platform')
parser_init_platform.add_argument('name', help='new platform name')
parser_init_platform.set_defaults(func=cmd.init_platform)

parser_init_gpu_platform = subparsers_init.add_parser('gpu-platform', help='new GPU platform')
parser_init_gpu_platform.add_argument('name', help='new platform name')
parser_init_gpu_platform.add_argument('--backend', help='setup new platform with specified backend')
parser_init_gpu_platform.set_defaults(func=cmd.init_gpu_platform)

parser_init_gpu_backend = subparsers_init.add_parser('backend', help='new GPU backend')
parser_init_gpu_backend.add_argument('name', help='new backend name')
parser_init_gpu_backend.set_defaults(func=cmd.init_gpu_backend)

parser_init.set_defaults(func=lambda _: parser_init.print_help())

parser.set_defaults(func=lambda _: parser.print_help())

args = parser.parse_args()
args.func(args)
