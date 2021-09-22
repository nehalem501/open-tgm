/* TextureID.h - GPU */

#ifndef TEXTURE_ID_H
#define TEXTURE_ID_H

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
        DIGITS,
        NB_TEXTURES
    };
}

#endif // TEXTURE_ID_H
