/* Texture.cpp - 3DS */

#include <stdlib.h>
#include <string.h>
#include <pspsdk.h>
#include <Debug.h>
#include <Texture.h>

/*static inline GPU_TEXCOLOR to_3ds_texture_format(uint8_t format) {
    switch (format) {
        case TexturesFormat::RGBA8: return GPU_RGBA8;
        case TexturesFormat::RGB8: return GPU_RGB8;
        case TexturesFormat::RGBA5551: return GPU_RGBA5551;
        case TexturesFormat::RGB565: return GPU_RGB565;
        case TexturesFormat::LA8: return GPU_LA8;
        case TexturesFormat::L8: return GPU_L8;
        case TexturesFormat::A8: return GPU_A8;
        case TexturesFormat::LA4: return GPU_LA4;
        case TexturesFormat::L4: return GPU_L4;
        case TexturesFormat::A4: return GPU_A4;
        case TexturesFormat::ETC1: return GPU_ETC1;
    }

    // TODO: error
    return GPU_RGBA8;
}*/

void free_texture(Texture& /*texture*/) {
    //C3D_TexDelete(&texture.handle);
}

/*static void swizzle(uint8_t* dest, const uint8_t* source, int width, int height) {
    const int rowblocks = (width / 16);
    const int rowblocks_add = (rowblocks - 1) * 128;
    size_t block_address = 0;
    const unsigned int* img = (unsigned int*) source;

    for (int j = 0; j < height; j++) {
        unsigned int *block = (unsigned int*) (dest + block_address);

        for (int i = 0; i < rowblocks; i++) {
            *block++ = *img++;
            *block++ = *img++;
            *block++ = *img++;
            *block++ = *img++;

            block += 28;
        }

        if ((j & 0x7) == 0x7)
            block_address += rowblocks_add;

        block_address += 16;
    }
}*/

void load_texture(Texture& texture, const uint8_t* img_data, const size_t length) {
    texture.handle_ptr()->data = (uint8_t*) malloc(length);
    texture.handle_ptr()->format = GU_PSM_8888; // TODO other formats

    //if (texture.width >= 16 || texture.height >= 16) {
    //    swizzle(texture.handle.data, img_data, texture.width, texture.height);
    //    texture.handle.swizzled = true;
    //} else {
        memcpy(texture.handle().data, img_data, length);
        texture.handle_ptr()->swizzled = false;
    //}
    //printd("copied texture " << (int) texture.handle.data << " len " << length);

    //sceKernelDcacheWritebackRange(texture.handle.data, length);
}
