/* Font.cpp - GPU */

#include "Font.h"

TextureID font_to_texture(FontID id) {
    switch (id) {
        case FontID::UI_FONT:
            return TextureID::TEXT;

        case FontID::LABEL_FONT:
            return TextureID::LABELS;

        case FontID::DIGITS_FONT:
            return TextureID::DIGITS;

        default:
            return TextureID::NONE;
    }
}
