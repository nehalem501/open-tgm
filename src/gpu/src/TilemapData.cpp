/* TilemapData.cpp - GPU */

#include <TargetTypes.h>
#include "Vector.h"
#include "TilemapData.h"

void TilemapData::update(const TilemapDataEntry& entry) {
    m_data.resize(entry.nb_tiles);

    const unsigned int tiles_per_line = entry.width / tile_size;

    const gpu_float_t gpu_width = entry.width;
    const gpu_float_t gpu_height = entry.height;

    for (size_t i = 0; i < m_data.size(); i++) {
        const unsigned int tile_x = i % tiles_per_line;
        const unsigned int tile_y = i / tiles_per_line;

        const gpu_float_t x1 = tile_x * entry.texture_tile_size;
        const gpu_float_t y1 = tile_y * entry.texture_tile_size;
        const gpu_float_t x2 = x1 + entry.texture_tile_size;
        const gpu_float_t y2 = y1 + entry.texture_tile_size;

        m_data[i] = TileData(gpu_width, gpu_height, x1, y1, x2, y2);
    }
}
