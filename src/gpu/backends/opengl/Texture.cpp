/* Texture.cpp - OpenGL */

#include "lodepng.h"
#include <TargetTypes.h>
#include "GPUTypes.h"
#include <Texture.h>

static texture_t empty_tex;
static texture_t background_tex;
//static texture_t tileset_tex;
//static texture_t outline_tex;
static texture_t frame_tex;
static texture_t digits_tex;
//static texture_t labels_tex;
static texture_t text_tex;
//static texture_t grades_tex;
//static texture_t timer_tex;

texture_t& get_texture(TextureID id) {
    switch(id) {
        /*case TexturesID::BACKGROUND:
            return background_tex;

        case TexturesID::BLOCKS:
            return tileset_tex;

        case TexturesID::OUTLINE:
            return outline_tex;*/

        case TexturesID::DIGITS:
            return digits_tex;

        case TexturesID::TEXT:
            return text_tex;

        case TexturesID::FRAME:
            return frame_tex;

        default:
            return empty_tex;
    }
}

texture_t upload_texture(
    const uint8_t* image,
    const unsigned int width,
    const unsigned int height) {

    texture_t id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);

    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    //glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        GL_RGBA8,
        width,
        height,
        0,
        GL_RGBA,
        GL_UNSIGNED_BYTE,
        image);

    return id;
}

static void load_texture(texture_t& texture, const char* path) {
    FILE *file = fopen(path, "r");

    if (file == NULL) {
        printf("Error: Could not open texture file %s\n", path);
        return; // TODO
    }

    // obtain file size:
    fseek (file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // allocate memory to contain the whole file:
    uint8_t *file_data = (uint8_t*) malloc(sizeof(uint8_t) * file_size);
    if (file_data == NULL) {
        printf("Error: Could not allocate memory\n");
        return; // TODO
    }

    // copy the file into the buffer:
    long result = fread(file_data, 1, file_size, file);
    if (result != file_size) {
        printf("Error: Could not read file %s\n", path);
        return; // TODO
    }

    fclose(file);

    unsigned int width, height;
    uint8_t* image;

    lodepng_decode32(&image, &width, &height, file_data, file_size);

    texture = upload_texture(image, width, height);

    free(image);

    printf("Loaded: %s\n", path);
}

void load_textures() { // TODO size
    // Empty texture is generated;
    const unsigned int height = 16;
    const unsigned int width = 16;
    uint8_t image[height * width * sizeof(uint8_t) * 4];

    for (unsigned int i = 0; i < height * width * sizeof(uint8_t) * 4; i++) {
        image[i] = 0xFFu;
    }

    empty_tex = upload_texture(image, width, height);

    //load_texture(background_tex, "/Users/tomek/open-tgm/data/resources/9px/background.png");
    background_tex = empty_tex;

    load_texture(frame_tex, "/Users/tomek/open-tgm/data/resources/8px/frame.png");
    load_texture(text_tex, "/Users/tomek/open-tgm/data/resources/8px/ui_font.png");
    load_texture(digits_tex, "/Users/tomek/open-tgm/data/resources/8px/digits_font.png");
    //load_texture(tileset_tex, "/Users/tomek/open-tgm/data/resources/9px/tileset.png");
    //load_texture(outline_tex, "/Users/tomek/open-tgm/data/resources/9px/outline.png");
}
