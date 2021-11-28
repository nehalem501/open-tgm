#!/usr/bin/env python3

import argparse
import ctypes
import os
import platform

from configparser import ConfigParser
from itertools import chain
from pathlib import Path
from globals import BUILD_DIR, TOOLS_DIR
from glyphs import ALL_GLYPHS

parser = argparse.ArgumentParser()
parser.add_argument('-i', '--input', required=True)
parser.add_argument('-m', '--metadata', required=True)
parser.add_argument('-o', '--output', required=True)
#parser.add_argument('-n', '--name', required=True)
parser.add_argument('-f', '--format', default='rgba8')
parser.add_argument('-c', '--compress', action='store_true')
args = parser.parse_args()

root_dir = Path(__file__).parent.parent
build_dir = root_dir.joinpath(BUILD_DIR).joinpath(TOOLS_DIR)
lib = build_dir.joinpath('img2tx').joinpath('img2tx')
if os.name != 'nt':
    if platform.system() == 'Darwin':
        lib = lib.with_suffix('.dylib')
    else:
        lib = lib.with_suffix('.so')

img2txlib = ctypes.CDLL(lib)

img2txlib.new_textures_data.restype = ctypes.c_void_p
img2txlib.new_textures_data.argtypes = []

img2txlib.textures_data_add.restype = None
img2txlib.textures_data_add.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_uint, ctypes.c_uint, ctypes.c_uint, ctypes.c_uint]

img2txlib.new_tilemap_data.restype = ctypes.c_void_p
img2txlib.new_tilemap_data.argtypes = [ctypes.c_char_p, ctypes.c_uint]

img2txlib.new_glyphs_data.restype = ctypes.c_void_p
img2txlib.new_glyphs_data.argtypes = [ctypes.c_char_p]

img2txlib.glyphs_data_add.restype = None
img2txlib.glyphs_data_add.argtypes = [ctypes.c_void_p, ctypes.c_char, ctypes.c_uint, ctypes.c_uint, ctypes.c_uint, ctypes.c_uint, ctypes.c_uint]

img2txlib.run.restype = None
img2txlib.run.argtypes = [ctypes.c_char_p, ctypes.c_char_p, ctypes.c_char_p, ctypes.c_void_p, ctypes.c_uint, ctypes.c_bool]

data = None
tile_size = -1

parser = ConfigParser(delimiters=('='))
with open(args.metadata) as lines:
    default_section = 'top'
    lines = chain(['[' + default_section + ']'], lines)
    parser.read_file(lines)
    type = parser[default_section]['type']
    tile_size = int(parser[default_section]['tile_size'])

    if type == 'texture':
        texture_nb = int(parser[default_section]['texture_nb'])
        textures_data = img2txlib.new_textures_data()

        for i in range(texture_nb):
            data = parser[default_section][f'texture_{i}'].split(',')
            id = parser[default_section][f'texture_{i}_id']
            if len(data) != 4:
                raise Exception('error') # TODO
            img2txlib.textures_data_add(
                textures_data,
                id.encode('utf-8'),
                int(data[0]),
                int(data[1]),
                int(data[2]),
                int(data[3]))

        data = textures_data

    elif type == 'tilemap':
        id = parser[default_section]['id']
        tile_nb = parser[default_section]['tile_nb']
        tilemap_data = img2txlib.new_tilemap_data(id.encode('utf-8'), int(tile_nb))

        data = tilemap_data

    elif type == 'glyphs':
        id = parser[default_section]['id']
        glyphs_data = img2txlib.new_glyphs_data(id.encode('utf-8'))
        for i in range(256):
            g = parser['glyphs'].get(ALL_GLYPHS[i].key)
            if g is not None:
                entry = g.split(',')
                img2txlib.glyphs_data_add(
                    glyphs_data,
                    i,
                    int(entry[0]),
                    int(entry[1]),
                    int(entry[2]),
                    int(entry[3]),
                    int(entry[4]))

        data = glyphs_data

    img2txlib.run(
        args.input.encode('utf-8'),
        args.output.encode('utf-8'),
        args.format.encode('utf-8'),
        data,
        tile_size,
        args.compress)
