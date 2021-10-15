/* Texture.cpp - GPU */

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
