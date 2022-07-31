/* TextureEnums.h - GPU */

#ifndef TEXTURE_ENUMS_H
#define TEXTURE_ENUMS_H

enum struct TextureID: unsigned int {
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

namespace TextureType {
    enum {
        TEXTURE = 1,
        TILEMAP = 2,
        GLYPHS = 3
    };
}

namespace TexturesFormat {
    enum {
        A4 = 0,
        L4,
        A8,
        L8,
        LA4,
        LA8,
        RGB332,
        RGB565,
        RGB8,
        RGBA2,
        RGBA4,
        RGBA5551,
        RGBA8,
        DXT1,
        DXT23,
        DXT45,
        ETC1,
        ETC2_RGB,
        ETC2_RGBA,
        ASTC, // TODO
        NB_FORMATS
    };
}

namespace TextureFileHeader {
    enum {
        BYTE_0 = 0x54u,
        BYTE_1 = 0x58u,
        BYTE_2 = 0x46u,
        BYTE_3 = 0x89u,
        BYTE_4 = 0x0Du,
        BYTE_5 = 0x0Au,
        BYTE_6 = 0x1Au,
        BYTE_7 = 0x0Au,
    };
}

#ifdef DEBUG
void printd_internal(TextureID id);
#endif

#endif // TEXTURE_ENUMS_H
