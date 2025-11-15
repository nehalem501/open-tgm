/* TilemapManager.h - GPU */

#ifndef GPU_TILEMAP_MANAGER_H
#define GPU_TILEMAP_MANAGER_H

#include "TilemapEnums.h"
#include "TilemapData.h"

class TilemapManager {
    public:
        static const TilemapManager& get();
        static TilemapManager& get_mutable();

        static size_t get_tiles_nb(TilemapID id); // TODO constexpr

        const TilemapData& get_data(TilemapID id) const;
        TilemapData& get_data_mutable(TilemapID id);

        void load_empty(unsigned int current_tile_size);

    private:
        TilemapData m_data[(size_t) TilemapID::NB_TILEMAPS];
};

#endif // GPU_TILEMAP_MANAGER_H
