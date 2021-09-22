/* list.cpp - Tool for generating C headers of textures list info */

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <sstream>
#include <iostream>
#include "common.h"

class Entry {
    public:
        int get_tilesize() { return tilesize; }
        virtual int get_type() = 0;

    protected:
        int tilesize;
};

class Textures : public Entry {
    public:
        Textures(std::vector<int> values, std::string filename) {
            tilesize = values[1];
            int textures_nb = values[2];

            if (values.size() < (size_t) textures_nb + 3) {
                exit_error("Entry inside '" + filename + "' of 'Textures' type has wrong number of values");
            }

            for (int i = 0; i < textures_nb; i++) {
                std::stringstream symbol;
                symbol << get_filename(filename) << "_" << i;
                id_and_symbols.push_back(std::make_pair(values[i + 3], symbol.str()));
            }
        }

        int get_type() { return AssetType::Texture; }
        std::vector<std::pair<TextureID, std::string> >& get_id_and_symbols() { return id_and_symbols; }

    private:
        std::vector<std::pair<TextureID, std::string> > id_and_symbols;
};

class SingleTexture : public Entry {
    public:
        SingleTexture(int tilesize, std::pair<TextureID, std::string> id_and_symbol) {
            this->tilesize = tilesize;
            id = id_and_symbol.first;
            symbol = id_and_symbol.second;
        }

        int get_type() { return AssetType::Texture; }
        std::string get_symbol() { return symbol; }

    private:
        std::string symbol;
        TextureID id;
};

class Tilemap : public Entry {
    public:
        Tilemap(std::vector<int> values, std::string filename) {
            tilesize = values[1];
            id = values[2];
            symbol = get_filename(filename);
        }

        int get_type() { return AssetType::Tilemap; }
        TextureID get_id() { return id; }
        std::string get_symbol() { return symbol; }

    private:
        std::string symbol;
        TextureID id;
};

class Glyphs : public Entry {
    public:
        Glyphs(std::vector<int> values, std::string filename) {
            tilesize = values[1];
            id = values[2];
            symbol = get_filename(filename);
        }

        int get_type() { return AssetType::Glyphs; }
        TextureID get_id() { return id; }
        std::string get_symbol() { return symbol; }

    private:
        std::string symbol;
        TextureID id;
};

Entry* decode(std::string input, std::string filename) {
    std::vector<int> values = split(input);
    if (values.size() < 3) {
        exit_error("Entry inside '" + filename + "' has wrong number of values");
    }

    switch (values[0]) {
        case AssetType::Texture:
            return new Textures(values, filename);
        case AssetType::Tilemap:
            return new Tilemap(values, filename);
        case AssetType::Glyphs:
            return new Glyphs(values, filename);
    }

    exit_error("Entry inside '" + filename + "' has bad asset type");

    // Not reachable
    return NULL;
}

std::string read_metadata_in_file(std::string filename) {
    std::ifstream file(filename);
    std::string line;

    while (getline(file, line)) {
        if (line.rfind("// @", 0) == 0) {
            return line.substr(4);
        }
    }
    if (!file.eof()) {
        exit_error("Cannot read file '" + filename + "'");
    }

    exit_error("Missing metadata entry inside '" + filename + "'");

    // Not reachable
    return NULL;
}

void add_empty(std::stringstream& out) {
    out << "const AssetDataEntryItem " << texture_id_to_string(TexturesID::NONE) << "_items[] = {" << std::endl;
    out << "    AssetDataEntryItem(TextureData(16, 16, 0, 0, 16, 16), 0)," << std::endl;
    out << "};" << std::endl;
    out << std::endl;
}

class Database {
    public:
        Database(std::vector<std::string> file_list) {
            for (unsigned int i = 0; i < file_list.size(); i++) {
                std::string metadata = read_metadata_in_file(file_list[i]);
                Entry* entry = decode(metadata, file_list[i]);
                int tilesize = entry->get_tilesize();

                switch (entry->get_type()) {
                    case AssetType::Texture: {
                        Textures* textures_entry = (Textures*) entry;
                        auto id_and_symbols = textures_entry->get_id_and_symbols();
                        for (unsigned int i = 0; i < id_and_symbols.size(); i++) {
                            textures[id_and_symbols[i].first][tilesize] = new SingleTexture(tilesize, id_and_symbols[i]);
                            if (!nb_items.count(id_and_symbols[i].first)) {
                                nb_items[id_and_symbols[i].first] = 0;
                            }
                            nb_items[id_and_symbols[i].first] += 1;
                        }
                    }
                    break;

                    case AssetType::Tilemap: {
                        Tilemap* tilemap_entry = (Tilemap*) entry;
                        TextureID id = tilemap_entry->get_id();
                        tilemaps[id][tilesize] = tilemap_entry;
                        if (!nb_items.count(id)) {
                            nb_items[id] = 0;
                        }
                        nb_items[id] += 1;
                    }
                    break;

                    case AssetType::Glyphs: {
                        Glyphs* glyphs_entry = (Glyphs*) entry;
                        TextureID id = glyphs_entry->get_id();
                        glyphs[id][tilesize] = glyphs_entry;
                        if (!nb_items.count(id)) {
                            nb_items[id] = 0;
                        }
                        nb_items[id] += 1;
                    }
                    break;
                }
            }

            // TODO cleanup

            nb_items[TexturesID::NONE] = 1;

            //textures[TexturesID::BACKGROUND] = textures[TexturesID::NONE];
            glyphs[TexturesID::LABELS] = glyphs[TexturesID::TEXT];
        }

        void add_textures(std::stringstream& out) {
            for (auto i = textures.begin(); i != textures.end(); ++i) {
                if (i->first == TexturesID::NONE) {
                    // TODO cleanup
                    continue;
                }

                out << "const AssetDataEntryItem " << texture_id_to_string(i->first) << "_items[] = {" << std::endl;
                for (auto j = i->second.begin(); j != i->second.end(); ++j) {
                    out << "    AssetDataEntryItem(" << j->second->get_symbol() << ", " << j->first << ")," << std::endl;
                }
                out << "};" << std::endl;
                out << std::endl;
            }
        }

        void add_tilemaps(std::stringstream& out) {
            for (auto i = tilemaps.begin(); i != tilemaps.end(); ++i) {
                out << "const AssetDataEntryItem " << texture_id_to_string(i->first) << "_items[] = {" << std::endl;
                for (auto j = i->second.begin(); j != i->second.end(); ++j) {
                    out << "    AssetDataEntryItem(" << j->second->get_symbol() << ", " << j->first << ")," << std::endl;
                }
                out << "};" << std::endl;
                out << std::endl;
            }
        }

        void add_glyphs(std::stringstream& out) {
            for (auto i = glyphs.begin(); i != glyphs.end(); ++i) {
                out << "const AssetDataEntryItem " << texture_id_to_string(i->first) << "_items[] = {" << std::endl;
                for (auto j = i->second.begin(); j != i->second.end(); ++j) {
                    out << "    AssetDataEntryItem(" << j->second->get_symbol() << ", " << j->first << ")," << std::endl;
                }
                out << "};" << std::endl;
                out << std::endl;
            }
        }

        void add_symbols_lut(std::stringstream& out) {
            out << "const AssetDataEntry asset_data_lut[TexturesID::NB_TEXTURES] = {" << std::endl;
            for (unsigned int i = 0; i < TexturesID::NB_TEXTURES; i++) {
                auto str = texture_id_to_string(i); // TODO cleanup
                if (i == TexturesID::BACKGROUND) {
                    str = "none";
                }
                out << "    AssetDataEntry(" << str << "_items, " << nb_items[i] << ")," << std::endl;
            }
            out << "};" << std::endl;
            out << std::endl;
        }

    private:
        std::map<TextureID, std::map<int, SingleTexture*> > textures;
        std::map<TextureID, std::map<int, Tilemap*> > tilemaps;
        std::map<TextureID, std::map<int, Glyphs*> > glyphs;
        std::map<TextureID, int> nb_items;
};

int main(int argc, char *argv[]) {
    if (argc < 3) {
        exit_error("Wrong number of parameters");
    }

    std::string output(argv[1]);

    std::vector<std::string> file_list;

    for (int i = 2; i < argc; i++) {
        file_list.push_back(std::string(argv[i]));
    }

    Database database(file_list);

    std::stringstream out;
    out << "/* " << output << " */" << std::endl;
    out << std::endl;
    out << "#ifndef DATA_ASSET_INFO_GPU_H" << std::endl;
    out << "#define DATA_ASSET_INFO_GPU_H" << std::endl;
    out << std::endl;
    out << "#include <data.h>" << std::endl;
    out << std::endl;

    for (unsigned int i = 0; i < file_list.size(); i++) {
        out << "#include \"" << get_filename(file_list[i]) << ".h\"" << std::endl;
    }
    out << std::endl;

    add_empty(out);

    database.add_textures(out);
    database.add_tilemaps(out);
    database.add_glyphs(out);

    database.add_symbols_lut(out);

    out << "constexpr AssetData asset_data(asset_data_lut);" << std::endl; // TODO

    out << std::endl;
    out << "#endif // DATA_ASSET_INFO_GPU_H" << std::endl;

    std::ofstream output_file(output);
    if (output_file) {
        output_file << out.str();
        output_file.close();
        return 0;
    } else {
        exit_error(output + ": could not create file");
    }

    return 0;
}
