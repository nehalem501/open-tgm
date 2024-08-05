/* TilemapManager.cpp - GPU */

#include "TilemapManager.h"

static TilemapManager tilemap_manager;

const TilemapManager& TilemapManager::get() {
    return tilemap_manager;
}

TilemapManager& TilemapManager::get_mutable() {
    return tilemap_manager;
}

const TilemapData& TilemapManager::get_data(TilemapID id) const {
    const TilemapData& t = m_data[(size_t) id];
    if (t.initialized()) {
        return t;
    } else {
        return m_data[0];
    }
}

void TilemapManager::load_empty(unsigned int current_tile_size) {
    //Vector<TileData> v = m_data[0].get_vec();
    //v.resize(32); // TODO find max tilemap size
    TileData* v = m_data[0].get_vec();

    TileData t = TileData(current_tile_size, current_tile_size, 0, 0, 0, 0);
    for (size_t i = 0; i < 32 /*v.size()*/; i++) {
        v[i] = t;
    }

    m_data[0].set_initialized(true);
}

size_t get_tiles_nb(TilemapID id) {
    switch(id) {
        case TilemapID::BLOCKS:
            return 32;

        case TilemapID::OUTLINE:
            return 16;

        default:
            return 0;
    }
}
