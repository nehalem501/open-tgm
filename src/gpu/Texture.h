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
        TEXT,
        LABELS,
        TIMER,
        NB_TEXTURES
    };
}

#endif // TEXTURE_H
