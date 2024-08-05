/* Tilemap.cpp - GPU */

#include "Tilemap.h"

TextureID tilemap_to_texture(TilemapID id) {
    switch(id) {
        case TilemapID::BLOCKS:
            return TextureID::BLOCKS;

        case TilemapID::OUTLINE:
            return TextureID::OUTLINE;

        default:
            return TextureID::NONE;
    }
}
