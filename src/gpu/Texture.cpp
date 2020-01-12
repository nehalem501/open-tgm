/* Texture.cpp - GPU */

#include <GPUImpl.h>
#include "Texture.h"

static Texture textures[TextureID::NB_TEXTURES];

Texture* get_texture(unsigned int id) {
    return &textures[id];
}
