/* Texture.h - GPU */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GPUTypes.h>

typedef unsigned int TextureID;

namespace TexturesID {
    enum {
        NONE = 0,
        BACKGROUND,
        BLOCKS,
        OUTLINE,
        TEXT,
        FRAME,
        LABELS,
        TIMER,
        NB_TEXTURES
    };
}

void load_textures();
texture_t& get_texture(TextureID id);

#endif // TEXTURE_H