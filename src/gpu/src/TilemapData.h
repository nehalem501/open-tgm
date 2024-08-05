/* TilemapData.h - GPU */

#ifndef TILEMAP_DATA_H
#define TILEMAP_DATA_H

#include <GPUTypes.h>
#include "Vector.h"
#include "TextureEnums.h"
#include "Vertex.h"

struct TileData {
    constexpr TileData() :
            tex_coord_top_left(0, 0),
            tex_coord_bottom_left(0, 0),
            tex_coord_bottom_right(0, 0),
            tex_coord_top_right(0, 0) { };

    constexpr TileData(
        float width,
        float height,
        float x1, float y1,
        float x2, float y2) :
            tex_coord_top_left(x1 / width, y1 / height),
            tex_coord_bottom_left(x1 / width, y2 / height),
            tex_coord_bottom_right(x2 / width, y2 / height),
            tex_coord_top_right(x2 / width, y1 / height) { };

    TexCoord tex_coord_top_left; // 0
    TexCoord tex_coord_bottom_left; // 1
    TexCoord tex_coord_bottom_right; // 2
    TexCoord tex_coord_top_right; // 3
};

struct TilemapDataEntry {
    constexpr TilemapDataEntry(
        unsigned int texture_tile_size,
        unsigned int width,
        unsigned int height,
        unsigned int nb_tiles) :
            texture_tile_size(texture_tile_size),
            width(width),
            height(height),
            nb_tiles(nb_tiles) { }

    unsigned int texture_tile_size, width, height, nb_tiles;
};

class TilemapData {
    public:
        constexpr TilemapData() : m_initialized(false), m_size(0) { }

        void update(const TilemapDataEntry& entry);

        inline const TileData& get(size_t index) const {
            return m_data[index];
        }

        // TODO:
        //Vector<TileData>& get_vec() { return m_data; }
        TileData* get_vec() { return m_data; }

        bool initialized() const { return m_initialized; }
        void set_initialized(bool value) { m_initialized = value; }

    private:
        bool m_initialized;
        //Vector<TileData> m_data;
        TileData m_data[32]; // TODO
        size_t m_size;
};

#endif // TILEMAP_DATA_H
