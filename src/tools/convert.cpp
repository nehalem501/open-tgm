/* convert.cpp - Tool for generating C headers of texture coordinates */

#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
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

void exit_error(std::string error_msg) {
    std::cout << error_msg << std::endl;
    exit(1);
}

std::string get_texture_nb(unsigned int n) {
    std::stringstream str;
    str << "texture_" << n;
    return str.str();
}

int string_to_int(std::string str) {
    int value = -1;
    std::istringstream input(str);
    input >> value;
    if (input.fail()) {
        return -1;
    }
    return value;
}

std::vector<int> split(std::string str) {
    std::string delimiter = ",";

    size_t start = 0;
    size_t end;
    size_t delim_len = delimiter.length();
    std::string token;

    std::vector<int> numbers;

    while ((end = str.find(delimiter, start)) != std::string::npos) {
        token = str.substr(start, end - start);
        start = end + delim_len;
        numbers.push_back(string_to_int(token));
    }

    numbers.push_back(string_to_int(str.substr(start)));

    return numbers;
}

std::string get_filename(std::string path) {
    #ifdef _WIN32
    std::string delimiter = "\\";
    #else
    std::string delimiter = "/";
    #endif

    size_t start = 0;
    size_t end;
    size_t delim_len = delimiter.length();

    while ((end = path.find(delimiter, start)) != std::string::npos) {
        start = end + delim_len;
    }

    std::string filename = path.substr(start);
    size_t position = filename.rfind(".");
    if (position == std::string::npos) {
        return filename;
    } else {
        filename.erase(position, std::string::npos);
        return filename;
    }
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

    public:
        Textures(unsigned int width, unsigned int height) : width(width), height(height) { }
        void add(TextureData data) { textures.push_back(data); }

        std::string to_file_data(std::string name) {
            std::stringstream out;
            out << "/* " << name << ".h */" << std::endl;
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

            return out.str();
        }
};

class Tilemap {
    private:
        unsigned int width, height;
        unsigned int nb_tiles;

    public:
        Tilemap(
            unsigned int width,
            unsigned int height,
            unsigned int nb_tiles) : width(width), height(height), nb_tiles(nb_tiles) { }

        std::string to_file_data(std::string name) {
            std::stringstream out;
            out << "/* " << name << ".h */" << std::endl;
            out << std::endl;
            out << "#include <TilemapData.h>" << std::endl;
            out << std::endl;

            out << "const TilemapData " << name  << " = { ";
            out << width << ", ";
            out << height;
            out << " };" << std::endl;

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

    public:
        void add(unsigned int position, Glyph g) {
            glyphs[position] = g;
        }

        std::string to_file_data(std::string name) {
            std::stringstream out;
            out << "/* " << name << ".h */" << std::endl;
            out << std::endl;
            out << "#include <Glyph.h>" << std::endl;
            out << std::endl;

            //const Glyph ui_font_9px[NB_GLYPHS] = {
            // /* 0x00 - NUL */ { 0, 0, 0, 0, 0 },
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
            std::vector<int> fields = split(texture_data);
            bool error = false;
            for (unsigned int j = 0; j < fields.size(); j++) {
                error = error || (fields[j] < 0);
            }
            if (error || fields.size() != 4) {
                exit_error(cmd_args.input_path() + " (type: texture): wrong data for " + get_texture_nb(i));
            }
            textures.add(TextureData(fields[0], fields[1], fields[2], fields[3]));
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
        unsigned int tile_nb = reader.GetInteger("", "tile_nb", 0);
        if (tile_nb == 0) {
            exit_error(cmd_args.input_path() + " (type: tilemap): missing tile_nb value");
        }

        unsigned int tile_size = reader.GetInteger("", "tile_size", 0);
        if (tile_size == 0) {
            exit_error(cmd_args.input_path() + " (type: tilemap): missing tile_size value");
        }

        Tilemap tilemap(width, height, tile_nb);

        std::ofstream output_file(cmd_args.output_path());
        if (output_file) {
            output_file << tilemap.to_file_data(get_filename(cmd_args.output_path()));
            output_file.close();
            return 0;
        } else {
            exit_error(cmd_args.output_path() + ": could not create file");
        }
    } else if (type == "glyphs") {
        if (reader.Sections().count("glyphs")) {
            Glyphs glyphs;
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
