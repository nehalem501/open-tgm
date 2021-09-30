#!/usr/bin/env python3

import argparse
import json
import textwrap
from configparser import ConfigParser
from itertools import chain
from glyphs import ALL_GLYPHS

class TextureData:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = int(x1)
        self.y1 = int(y1)
        self.x2 = int(x2)
        self.y2 = int(y2)

class Textures:
    textures = []

    def __init__(self, width, height):
        self.width = int(width)
        self.height = int(height)

    def add(self, data, id):
        self.textures += [data]
        self.textures_id += [id]

    def to_file(self, filename, name):
        with open(filename, 'w') as file:
            file.write(textwrap.dedent(f"""\
                /* {name}.h */

                #ifndef {name.upper()}_H
                #define {name.upper()}_H

                #include <Texture.h>
                """))

            for i, t in enumerate(self.textures):
                file.write(f"const TextureData {name}_{i}({self.width}, {self.height}, {t.x1}, {t.y1}, {t.x2}, {t.y2});")

            file.write(f"#endif // {name.upper()}_H")

    def encode(self, tile_size):
        #return json.dumps
        pass

    # TODO
    """std::string encode(int tilesize) {
        std::stringstream out;
        out << AssetType::Texture << ",";
        out << tilesize << ","; // TODO tile size -1
        out << textures.size() << ",";
        for (unsigned int i = 0; i < textures_id.size(); i++) {
            out << textures_id[i];
            if (i < textures_id.size() - 1) {
                out << ",";
            }
        }
        return out.str();
    }"""

class Tilemap:
    def __init__(self, width, height):
        self.width = int(width)
        self.height = int(height)

    def to_file(self, filename, name):
        with open(filename, 'w') as file:
            file.write(textwrap.dedent(f"""\
                /* {name}.h */

                #ifndef {name.upper()}_H
                #define {name.upper()}_H

                #include <TilemapData.h>

                const TilemapData {name} = {{{self.width}, {self.height}}};

                #endif // {name.upper()}_H
                """))

            # TODO
            #out << "// @" << encode(get_tilesize(name)) << std::endl;
            #out << std::endl;

    # TODO
    """std::string encode(int tilesize) {
        std::stringstream out;
        out << AssetType::Tilemap << ",";
        out << tilesize << ","; // TODO tile size -1
        out << id;
        return out.str();
    }"""

class Glyph:
    def __init__(self, x, y, width, height, offset):
        self.x = x
        self.y = y
        self.width = width
        self.height = height
        self.offset = offset

class Glyphs:
    glyphs = [Glyph(0, 0, 0, 0, 0)] * 256

    def add(self, position, g):
        self.glyphs[int(position)] = g

    def to_file(self, filename, name):
        with open(filename, 'w') as file:
            file.write(textwrap.dedent(f"""\
                /* {name}.h */

                #ifndef {name.upper()}_H
                #define {name.upper()}_H

                #include <Glyph.h>

                const Glyph {name}[NB_GLYPHS] = {{
                """))

            # TODO
            #out << "// @" << encode(get_tilesize(name)) << std::endl;
            #out << std::endl;

            for i, g in enumerate(self.glyphs):
                if i % 8 == 0 and i != 0:
                    file.write("\n")

                file.write(f"/* {i:#0{2}x} - {ALL_GLYPHS[i].name} */ {{{g.x}, {g.y}, {g.width}, {g.height}, {g.offset}}},")

            file.write(textwrap.dedent(f"""\
                }};

                #endif // {name.upper()}_H"""))

    # TODO
    """std::string encode(int tilesize) {
        std::stringstream out;
        out << AssetType::Glyphs << ",";
        out << tilesize << ","; // TODO tile size -1
        out << id;
        return out.str();
    }"""

def texture(output, name, parser, default_section, width, height):
    texture_nb = parser[default_section]['texture_nb']
    textures = Textures(width, height)

    for i in range(texture_nb):
        texture_data = parser[default_section][f'texture_{i}'].split(',')
        if len(texture_data) != 4:
            raise Exception('error') # TODO

        textures += TextureData(*texture_data)

    textures.to_file(output, name)

def tilemap(output, name, parser, default_section, width, height):
    tile_size = parser[default_section]['tile_size']
    tilemap = Tilemap(width, height)
    tilemap.to_file(output, name)

def glyphs(output, name, parser, default_section, width, height):
    glyphs = Glyphs()
    for i in range(256):
        g = parser['glyphs'].get(ALL_GLYPHS[i].key)
        if g is not None:
            entry = g.split()
            glyphs.add(i, Glyphs(*entry))

    glyphs.to_file(output, name)

def run(input, output):
    parser = ConfigParser()
    with open(input) as lines:
        default_section = 'top'
        lines = chain(['[' + default_section + ']'], lines)
        parser.read_file(lines)
        width = parser[default_section]['width']
        height = parser[default_section]['height']
        type = parser[default_section]['type']
        if type == 'texture':
            texture(output, parser, default_section, width, height)
        elif type == 'tilemap':
            tilemap(output, parser, default_section, width, height)
        elif type == 'glyphs':
            glyphs(output, parser, default_section, width, height)

parser = argparse.ArgumentParser()
parser.add_argument('-i', '--input', required=True)
parser.add_argument('-o', '--output', required=True)
parser.add_argument('-n', '--name', required=True)
args = parser.parse_args()
