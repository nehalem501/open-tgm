/* Texture.h - GPU */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <GPUTypes.h>

namespace TextureID {
    enum {
        BACKGROUND = 0,
        BLOCKS,
        TEXT,
        LABELS,
        TIMER,
        NB_TEXTURES
    };
}

class Texture {
    public:
        Texture() { };
        Texture(texture_t texture) : m_texture(texture) { };
    private:
        texture_t m_texture;
};

Texture* get_texture(unsigned int id);

#endif // TEXTURE_H
