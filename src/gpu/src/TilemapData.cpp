/* TilemapData.cpp - GPU */

#include <TargetTypes.h>
#include "Vector.h"
#include "TilemapData.h"
//#include <iostream>

void TilemapData::update(const TilemapDataEntry& entry) {
    // m_data.resize(entry.nb_tiles); ?? TODO
    m_size = entry.nb_tiles;

    const unsigned int tiles_per_line = entry.width / entry.texture_tile_size;
    /*std::cout << "tiles_per_line: " << tiles_per_line << std::endl;
    std::cout << "width: " << entry.width << std::endl;
    std::cout << "height: " << entry.height << std::endl;
    std::cout << "texture_tile_size: " << entry.texture_tile_size << std::endl;
    std::cout << "nb_tiles: " << entry.nb_tiles << std::endl;
    std::cout << "m_size: " << m_size << std::endl;*/

    for (size_t i = 0; i < m_size /*m_data.size()*/; i++) {
        const unsigned int tile_x = i % tiles_per_line;
        const unsigned int tile_y = i / tiles_per_line;

        const float x1 = tile_x * entry.texture_tile_size;
        const float y1 = tile_y * entry.texture_tile_size;
        const float x2 = x1 + entry.texture_tile_size;
        const float y2 = y1 + entry.texture_tile_size;

        m_data[i] = TileData(entry.width, entry.height, x1, y1, x2, y2);
        //std::cout << "i: " << i << ", x1: " << x1 << ", x2: " << x2 << std::endl;
    }
}
