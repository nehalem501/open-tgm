/* Texture.cpp - GPU */

#include <stdlib.h>
#include <zstd.h>
#include <Debug.h>
#include <data.h>
#include "Glyphs.h"
#include "TilemapData.h"
#include "Vector.h"
#include "Debug.h"
#include "Texture.h"

enum class HeaderStatus {
    Compressed,
    Uncompressed,
    Error
};

struct HeaderData {
    uint8_t format;
    size_t data_position;
    TextureID id;
    unsigned int width, height;
    unsigned int texture_tile_size;

    HeaderData() { }

    constexpr HeaderData(
        uint8_t format,
        size_t data_position,
        TextureID id,
        unsigned int width,
        unsigned int height,
        unsigned int texture_tile_size) :
            format(format),
            data_position(data_position),
            id(id),
            width(width),
            height(height),
            texture_tile_size(texture_tile_size) { }
};

static HeaderStatus check_header(const AssetEntry& entry) {
    if (entry.size < 16) {
        return HeaderStatus::Error;
    } else if (entry.data[0] == TextureFileHeader::BYTE_0 &&
               entry.data[1] == TextureFileHeader::BYTE_1 &&
               entry.data[2] == TextureFileHeader::BYTE_2 &&
               entry.data[3] == TextureFileHeader::BYTE_3 &&
               entry.data[4] == TextureFileHeader::BYTE_4 &&
               entry.data[5] == TextureFileHeader::BYTE_5 &&
               entry.data[6] == TextureFileHeader::BYTE_6 &&
               entry.data[7] == TextureFileHeader::BYTE_7)
    {
        return HeaderStatus::Uncompressed;
    } else if (entry.data[0] == 0x28u &&
               entry.data[1] == 0xB5u &&
               entry.data[2] == 0x2Fu &&
               entry.data[3] == 0xFDu) {
        return HeaderStatus::Compressed;
    }

    return HeaderStatus::Error;
}

static void decompress(uint8_t* uncompressed_data, size_t& uncompressed_size, const uint8_t* compressed_data, const size_t compressed_data_size) {
    unsigned long long const content_size = ZSTD_getFrameContentSize(compressed_data, compressed_data_size);
    if (content_size == ZSTD_CONTENTSIZE_ERROR) {
        // TODO
    }
    if (content_size == ZSTD_CONTENTSIZE_UNKNOWN) {
        // TODO
    }

    uncompressed_data = (uint8_t*) malloc((size_t) content_size);
    uncompressed_size = ZSTD_decompress(uncompressed_data, content_size, compressed_data, compressed_data_size);
    // TODO checkout decompress error
}

static void read_texture_header(HeaderData& header, const uint8_t* data, const size_t size) {
    uint8_t format = data[8];
    unsigned int width = 1 << data[9];
    unsigned int height = 1 << data[10];

    size_t position = 16;
    uint8_t texture_tilesize = data[12];
    uint8_t type = data[13];

    TextureID id = 0;

    switch (type) {
        case TextureType::TEXTURE: {
            unsigned int nb_textures = data[15];
            if (size < position + 4 + nb_textures * 5 * 4) {
                // TODO: error
                return;
            }
            for (unsigned int i = 0; i < nb_textures; i++) {
                id = data[position]; // TODO multiple textures
                uint32_t x1 = read_uint32(data + position + 4);
                uint32_t y1 = read_uint32(data + position + 8);
                uint32_t x2 = read_uint32(data + position + 12);
                uint32_t y2 = read_uint32(data + position + 16);
                printd("New texture data loaded: id=" << texture_to_str(id) <<
                    ", x1=" << x1 <<
                    ", y1=" << y1 <<
                    ", x2=" << x2 <<
                    ", y2=" << y2);
                set_texture_data(id, TextureData(width, height, x1, y1, x2, y2));
                position += 5 * 4;
            }
            break;
        }
        case TextureType::TILEMAP: {
            id = data[14];
            unsigned int nb_tiles = data[15];
            if (size < position + 4) {
                // TODO: error
                return;
            }
            printd("New tilemap data loaded: id=" << texture_to_str(id) << ", nb_tiles=" << nb_tiles);
            set_tilemap_data(id, TilemapDataEntry(texture_tilesize, width, height, nb_tiles));
            break;
        }
        case TextureType::GLYPHS: {
            id = data[14];
            unsigned int nb_glyphs = data[15];
            if (size < position + 4 + nb_glyphs * 6 * 4) {
                // TODO: error
                return;
            }
            clear_glyph_data(id);
            printd("New glyphs data loaded: id=" << texture_to_str(id) << ", nb_glyphs=" << nb_glyphs);
            for (unsigned int i = 0; i < nb_glyphs; i++) {
                uint8_t char_id = data[position];
                set_glyph_data(
                    id,
                    char_id,
                    Glyph(
                        (gpu_texcoord_t) read_uint32(data + position + 4),
                        (gpu_texcoord_t) read_uint32(data + position + 8),
                        (gpu_texcoord_t) read_uint32(data + position + 12),
                        (gpu_texcoord_t) read_uint32(data + position + 16),
                        (gpu_texcoord_t) read_uint32(data + position + 20)));
                position += 6 * 4;
            }
            break;
        }
    }

    header = HeaderData(format, position, id, width, height, texture_tilesize);
}

static void read_texture_data(const HeaderData& header, Texture* textures, const uint8_t* data, const size_t size) {
    size_t img_data_size = read_uint32(data + header.data_position);
    if (size != header.data_position + 4 + img_data_size) {
        // TODO: error
        return;
    }

    if (textures[header.id].initialized) {
        free_texture(textures[header.id]);
    }
    Texture texture;
    texture.width = header.width;
    texture.height = header.height;
    texture.format = header.format;

    printd("New texture loaded: id=" << header.id <<
        ", format=" << header.format <<
        ", width=" << header.width <<
        ", height=" << header.height);

    load_texture(texture, data + header.data_position + 4, img_data_size);
    texture.initialized = true;

    textures[header.id] = texture;
}

static void read_texture(Texture* textures, const AssetEntry& entry) {
    switch (check_header(entry)) {
        case HeaderStatus::Compressed: {
            uint8_t* uncompressed_data = NULL;
            size_t uncompressed_size = 0;
            decompress(uncompressed_data, uncompressed_size, entry.data, entry.size);
            HeaderData header;
            read_texture_header(header, uncompressed_data, uncompressed_size);
            read_texture_data(header, textures, uncompressed_data, uncompressed_size);
            free(uncompressed_data);
            return;
        }

        case HeaderStatus::Uncompressed: {
            HeaderData header;
            read_texture_header(header, entry.data, entry.size);
            read_texture_data(header, textures, entry.data, entry.size);
            return;
        }

        default:
            break;
    }
    // TODO error
}

// TODO duplicate code with function above
static void read_texture_metadata(HeaderData& header, const AssetEntry& entry) {
    switch (check_header(entry)) {
        case HeaderStatus::Compressed: {
            uint8_t* uncompressed_data = NULL;
            size_t uncompressed_size = 0;
            decompress(uncompressed_data, uncompressed_size, entry.data, entry.size);
            read_texture_header(header, uncompressed_data, uncompressed_size);
            free(uncompressed_data);
            return;
        }

        case HeaderStatus::Uncompressed: {
            read_texture_header(header, entry.data, entry.size);
            return;
        }

        default:
            break;
    }
    // TODO error
}

struct TextureEntry {
    bool loaded;
    AssetEntry data;

    TextureEntry(AssetEntry data) : loaded(false), data(data) { }

    void load() {
        loaded = true;
    }

    void unload() {
        loaded = false;
    }
};

class TexturesManager {
    public:
        TexturesManager() {
            for (TextureID i = 0; i < TexturesID::NB_TEXTURES; i++) {
                m_keys.push(Key());
            }
        }

        void add(TextureID id, unsigned int texture_tile_size, const AssetEntry& texture) {
            size_t position = m_data.size();
            Key& key = m_keys[id];
            // TODO sorted
            m_values.insert(key.position + key.length, Value(texture_tile_size, position));
            key.length++;
            for (TextureID i = 1; i < TexturesID::NB_TEXTURES; i++) {
                if (i != id && m_keys[i].position >= key.position) {
                    m_keys[i].position++;
                }
            }
            m_data.push(texture);
        }

        TextureEntry* get(unsigned int texture_tile_size, TextureID id) {
            // TODO missing
            Key& key = m_keys[id];
            for (size_t i = 0; i < key.length; i++) {
                if (m_values[i + key.position].size == texture_tile_size) {
                    return &m_data[m_values[i + key.position].position];
                }
            }
            return NULL;
        }

        size_t size() const { return m_data.size(); }

    private:
        struct Key {
            size_t position;
            size_t length;

            constexpr Key() : position(0), length(0) { }
            constexpr Key(size_t position, size_t length) : position(position), length(length) { }
        };

        struct Value {
            unsigned int size;
            size_t position;

            constexpr Value() : size(0), position(0) { }
            constexpr Value(unsigned int size, size_t position) : size(size), position(position) { }
        };

        Vector<Key> m_keys;
        Vector<Value> m_values;
        Vector<TextureEntry> m_data;
};

static TexturesManager textures_manager;

void register_textures(const Assets& assets) {
    for (unsigned int i = 0; i < assets.length; i++) {
        if (assets.entries[i].size == 0) {
            // TODO load from filesystem
        } else {
            HeaderData header;
            read_texture_metadata(header, assets.entries[i]);
            // TODO check for errors
            textures_manager.add(header.id, header.texture_tile_size, assets.entries[i]);
            printd("New texture registered: id=" << texture_to_str(header.id) << ", tile_size=" << header.texture_tile_size);
        }
    }
}

void refresh_textures(Texture* textures) {
    for (TextureID i = 1; i < TexturesID::NB_TEXTURES; i++) {
        TextureEntry* entry = textures_manager.get(tile_size, i);
        if (entry != NULL) {
            read_texture(textures, entry->data);
        }
    }
}
