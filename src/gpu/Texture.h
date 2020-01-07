/* Texture.h - GPU */

#ifndef TEXTURE_H
#define TEXTURE_H

#include <TargetTypes.h>

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
    private:
        texture_t m_texture;
};

Texture* get_texture(unsigned int id);

#endif // TEXTURE_H
