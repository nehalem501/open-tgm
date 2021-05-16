/* TilemapData.h - GPU */

#ifndef TILEMAPDATA_H
#define TILEMAPDATA_H

#include <GPUTypes.h>

struct TilemapData {
    constexpr TilemapData(
        gpu_float_t width,
        gpu_float_t height) : width(width), height(height) { }

    gpu_float_t width, height;
};

#endif // TILEMAPDATA_H
