/* convert.cpp - Tool for generating C headers of texture coordinates */

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include "common.h"
#include "glyphs.h"
#include "INIReader.h"

#define BUFFER_SIZE 4096

std::vector<std::string> split(std::string str, std::string delims) {
    size_t position = 0;
    size_t previous_position;
    std::vector<std::string> tokens;

    while (true) {
        previous_position = position;
        position = str.find_first_of(delims, previous_position);
        if (position == std::string::npos) {
            if (previous_position != position) {
                tokens.push_back(str.substr(previous_position));
            }
            break;
        }
        if (position != previous_position) {
            tokens.push_back(str.substr(previous_position, position));
        } else {
            position++;
        }
    }

    return tokens;
}

std::string get_texture_nb(unsigned int n) {
    std::stringstream str;
    str << "texture_" << n;
    return str.str();
}

std::string get_texture_nb_id(unsigned int n) {
    std::stringstream str;
    str << "texture_" << n << "_id";
    return str.str();
}

std::string to_upper(std::string input) {
    std::string output(input);
    for (unsigned int i = 0; i < output.size(); i++) {
        output[i] = toupper(output[i]);
    }
    return output;
}

std::string keep_digits(std::string input) {
    std::string digits;
    for (unsigned int i = 0; i < input.size(); i++) {
        if (isdigit(input[i])) {
            digits.push_back(input[i]);
        }
    }
    return digits;
}

int get_tilesize(std::string input) {
    std::size_t found = input.find_last_of("_");
    if (found == std::string::npos) {
        // TODO
        return -1;
    }
    std::string tile_size_str = keep_digits(input.substr(found + 1));
    return string_to_int(tile_size_str);
}

struct TextureData {
    unsigned int x1, y1, x2, y2;

    TextureData(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2) :
        x1(x1), y1(y1), x2(x2), y2(y2) { }
};

class Textures {
    private:
        unsigned int width, height;
        std::vector<TextureData> textures;
        std::vector<TextureID> textures_id;

    public:
        Textures(unsigned int width, unsigned int height) : width(width), height(height) { }

        void add(TextureData data, TextureID id) {
            textures.push_back(data);
            textures_id.push_back(id);
        }

        std::string to_file_data(std::string name) {
            std::stringstream out;
            out << "/* " << name << ".h */" << std::endl;
            out << std::endl;
            out << "#ifndef " << to_upper(name) << "_H" << std::endl;
            out << "#define " << to_upper(name) << "_H" << std::endl;
            out << std::endl;

            out << "// @" << encode(get_tilesize(name)) << std::endl;
            out << std::endl;

            out << "#include <Texture.h>" << std::endl;
            out << std::endl;

            for (unsigned int i = 0; i < textures.size(); i++) {
                out << "const TextureData " << name << "_" << i << "(";
                out << width << ", ";
                out << height << ", ";
                out << textures[i].x1 << ", ";
                out << textures[i].y1 << ", ";
                out << textures[i].x2 << ", ";
                out << textures[i].y2;
                out << ");" << std::endl;
            }

            out << std::endl;
            out << "#endif // " << to_upper(name) << "_H" << std::endl;

            return out.str();
        }

        std::string encode(int tilesize) {
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
        }
};

class Tilemap {
    private:
        unsigned int width, height;
        //unsigned int nb_tiles;
        TextureID id;

    public:
        Tilemap(
            unsigned int width,
            unsigned int height,
            //unsigned int nb_tiles,
            TextureID id) : width(width), height(height), /*nb_tiles(nb_tiles),*/ id(id) { }

        std::string to_file_data(std::string name) {
            std::stringstream out;
            out << "/* " << name << ".h */" << std::endl;
            out << std::endl;
            out << "#ifndef " << to_upper(name) << "_H" << std::endl;
            out << "#define " << to_upper(name) << "_H" << std::endl;
            out << std::endl;

            out << "// @" << encode(get_tilesize(name)) << std::endl;
            out << std::endl;

            out << "#include <TilemapData.h>" << std::endl;
            out << std::endl;

            out << "const TilemapData " << name  << " = { ";
            out << width << ", ";
            out << height;
            out << " };" << std::endl;
            out << std::endl;
            out << "#endif // " << to_upper(name) << "_H" << std::endl;

            return out.str();
        }

        std::string encode(int tilesize) {
            std::stringstream out;
            out << AssetType::Tilemap << ",";
            out << tilesize << ","; // TODO tile size -1
            out << id;
            return out.str();
        }
};

struct Glyph {
    unsigned int x, y;
    unsigned int width, height;
    unsigned int offset;

    Glyph(): x(0), y(0), width(0), height(0), offset(0) { }

    Glyph(
        unsigned int x,
        unsigned int y,
        unsigned int width,
        unsigned int height,
        unsigned int offset) : x(x), y(y), width(width), height(height), offset(offset) { }
};

class Glyphs {
    private:
        Glyph glyphs[256];
        TextureID id;

    public:
        Glyphs(TextureID id) : id(id) { }

        void add(unsigned int position, Glyph g) {
            glyphs[position] = g;
        }

        std::string to_file_data(std::string name) {
            std::stringstream out;
            out << "/* " << name << ".h */" << std::endl;
            out << std::endl;
            out << "#ifndef " << to_upper(name) << "_H" << std::endl;
            out << "#define " << to_upper(name) << "_H" << std::endl;
            out << std::endl;

            out << "// @" << encode(get_tilesize(name)) << std::endl;
            out << std::endl;

            out << "#include <Glyph.h>" << std::endl;
            out << std::endl;
            out << "const Glyph " << name << "[NB_GLYPHS] = {" << std::endl;

            for (unsigned int i = 0; i < 256; i++) {
                if (i % 8 == 0 && i != 0) {
                    out << std::endl;
                }

                out << "/* 0x";
                std::ios_base::fmtflags flags(out.flags());
                out << std::uppercase << std::setfill('0') << std::setw(2) << std::hex << i;
                out.flags(flags);
                out << " - " << all_glyphs[i].name << " */ { ";
                out << glyphs[i].x << ", ";
                out << glyphs[i].y << ", ";
                out << glyphs[i].width << ", ";
                out << glyphs[i].height << ", ";
                out << glyphs[i].offset << " }," << std::endl;
            }

            out << "};" << std::endl;
            out << std::endl;
            out << "#endif // " << to_upper(name) << "_H" << std::endl;

            return out.str();
        }

        std::string encode(int tilesize) {
            std::stringstream out;
            out << AssetType::Glyphs << ",";
            out << tilesize << ","; // TODO tile size -1
            out << id;
            return out.str();
        }
};

class CmdArgs {
    private:
        std::string input;
        std::string output;

    public:
        CmdArgs(int argc, char *argv[]) {
            if (argc != 3) {
                exit_error("Wrong number of parameters");
            }

            input = std::string(argv[1]);
            output = std::string(argv[2]);
        }

        std::string input_path() { return input; }
        std::string output_path() { return output; }
};

int main(int argc, char *argv[]) {
    CmdArgs cmd_args(argc, argv);

    INIReader reader(cmd_args.input_path());
    if (reader.ParseError()) {
        exit_error("Could not read file '" + cmd_args.input_path() + "'");
    }

    unsigned int width = reader.GetInteger("", "width", 0);
    if (width == 0) {
        exit_error(cmd_args.input_path() + ": missing width value");
    }

    unsigned int height = reader.GetInteger("", "height", 0);
    if (height == 0) {
        exit_error(cmd_args.input_path() + ": missing height value");
    }

    std::string type = reader.Get("", "type", "");
    if (type.empty()) {
        exit_error(cmd_args.input_path() + ": missing type value");
    }

    if (type == "texture") {
        unsigned int texture_nb = reader.GetInteger("", "texture_nb", 0);
        if (texture_nb == 0) {
            exit_error(cmd_args.input_path() + " (type: texture): missing texture_nb value");
        }

        Textures textures(width, height);

        for (unsigned int i = 0; i < texture_nb; i++) {
            std::string texture_data = reader.Get("", get_texture_nb(i), "");
            if (texture_data.empty()) {
                exit_error(cmd_args.input_path() + " (type: texture): missing texture data for " + get_texture_nb(i));
            }

            std::string texture_id = reader.Get("", get_texture_nb_id(i), "");
            if (texture_id.empty()) {
                exit_error(cmd_args.input_path() + " (type: texture): missing texture id for " + get_texture_nb_id(i));
            }

            std::vector<int> fields = split(texture_data);
            bool error = false;
            for (unsigned int j = 0; j < fields.size(); j++) {
                error = error || (fields[j] < 0);
            }
            if (error || fields.size() != 4) {
                exit_error(cmd_args.input_path() + " (type: texture): wrong data for " + get_texture_nb(i));
            }
            textures.add(TextureData(fields[0], fields[1], fields[2], fields[3]), string_to_texture_id(texture_id));
        }

        std::ofstream output_file(cmd_args.output_path());
        if (output_file) {
            output_file << textures.to_file_data(get_filename(cmd_args.output_path()));
            output_file.close();
            return 0;
        } else {
            exit_error(cmd_args.output_path() + ": could not create file");
        }
    } else if (type == "tilemap") {
        std::string texture_id = reader.Get("", "id", "");
        if (texture_id.empty()) {
            exit_error(cmd_args.input_path() + " (type: tilemap): missing id");
        }

        /*unsigned int tile_nb = reader.GetInteger("", "tile_nb", 0);
        if (tile_nb == 0) {
            exit_error(cmd_args.input_path() + " (type: tilemap): missing tile_nb value");
        }*/

        unsigned int tile_size = reader.GetInteger("", "tile_size", 0);
        if (tile_size == 0) {
            exit_error(cmd_args.input_path() + " (type: tilemap): missing tile_size value");
        }

        Tilemap tilemap(width, height, /*tile_nb,*/ string_to_texture_id(texture_id));

        std::ofstream output_file(cmd_args.output_path());
        if (output_file) {
            output_file << tilemap.to_file_data(get_filename(cmd_args.output_path()));
            output_file.close();
            return 0;
        } else {
            exit_error(cmd_args.output_path() + ": could not create file");
        }
    } else if (type == "glyphs") {
        std::string texture_id = reader.Get("", "id", "");
        if (texture_id.empty()) {
            exit_error(cmd_args.input_path() + " (type: glyphs): missing id");
        }

        if (reader.Sections().count("glyphs")) {
            Glyphs glyphs(string_to_texture_id(texture_id));
            for (unsigned int i = 0; i < 256; i++) {
                std::string glyph_data = reader.Get("glyphs", all_glyphs[i].key, "");
                if (!glyph_data.empty()) {
                    std::vector<int> fields = split(glyph_data);
                    bool error = false;
                    for (unsigned int j = 0; j < fields.size(); j++) {
                        error = error || (fields[j] < 0);
                    }
                    if (error || fields.size() != 5) {
                        exit_error(cmd_args.input_path() + " (type: glyphs): wrong data for: " + all_glyphs[i].key);
                    }
                    glyphs.add(i, Glyph(fields[0], fields[1], fields[2], fields[3], fields[4]));
                }
            }

            std::ofstream output_file(cmd_args.output_path());
            if (output_file) {
                output_file << glyphs.to_file_data(get_filename(cmd_args.output_path()));
                output_file.close();
                return 0;
            } else {
                exit_error(cmd_args.output_path() + ": could not create file");
            }
        } else {
            exit_error(cmd_args.input_path() + " (type: glyphs): missing glyphs section");
        }
    } else {
        exit_error("'" + type + "' is not a valid value for the type key");
    }

    return -1;
}
