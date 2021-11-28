/* GPUTypes.h - SCEGU */

#ifndef GPU_TYPES_SCEGU_H
#define GPU_TYPES_SCEGU_H

#include <stdint.h>

struct SceGuTexture {
    uint8_t* data;
    int format; // TODO
    bool swizzled;
};

typedef float gpu_coord_t;
typedef float gpu_texcoord_t;
typedef uint8_t gpu_color_t;
typedef uint16_t gpu_indices_t;
typedef SceGuTexture texture_t;

void* get_static_vram_texture(unsigned int bytes);

#endif // GPU_TYPES_SCEGU_H
