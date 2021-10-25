/* Texture.cpp - GPU */

#include <stdlib.h>
#include <zstd.h>
#include "Texture.h"

static Texture empty_tex; // TODO

Texture& get_texture(TextureID id) {
    switch(id) {
        /*case TexturesID::BACKGROUND:
            return background_tex;

        case TexturesID::BLOCKS:
            return tileset_tex;

        case TexturesID::OUTLINE:
            return outline_tex;

        case TexturesID::TEXT:
            return text_tex;

        case TexturesID::FRAME:
            return frame_tex;*/

        default:
            return empty_tex;
    }
}

void load_textures() {
    
}

TextureFile::TextureFile(const uint8_t* compressed_data, const size_t compressed_data_size) : m_raw_data(NULL) {
    unsigned long long const content_size = ZSTD_getFrameContentSize(compressed_data, compressed_data_size);
    if (content_size == ZSTD_CONTENTSIZE_ERROR) {
        // TODO
    }
    if (content_size == ZSTD_CONTENTSIZE_UNKNOWN) {
        // TODO
    }

    m_raw_data = (uint8_t*) malloc((size_t) content_size);
    m_size = ZSTD_decompress(m_raw_data, content_size, compressed_data, compressed_data_size);
    // TODO checkout decompress error
}

TextureFile::~TextureFile() {
    free(m_raw_data);
}
