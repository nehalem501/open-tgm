/* Debug.h - GPU */

#ifndef DEBUG_GPU_H
#define DEBUG_GPU_H

#include "TextureEnums.h"

#ifdef DEBUG

const char* texture_to_str(TextureID id) {
    switch (id) {
        case TexturesID::NONE:
            return "None";
        case TexturesID::BACKGROUND:
            return "Background";
        case TexturesID::BLOCKS:
            return "Blocks";
        case TexturesID::OUTLINE:
            return "Outline";
        case TexturesID::TEXT:
            return "Text";
        case TexturesID::FRAME:
            return "Frame";
        case TexturesID::LABELS:
            return "Labels";
        case TexturesID::DIGITS:
            return "Digits";
    }

    return "";
}

#endif

#endif // DEBUG_GPU_H
