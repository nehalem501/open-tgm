/* TilemapEnums.h - GPU */

#ifndef TILEMAP_ENUMS_H
#define TILEMAP_ENUMS_H

#include <stddef.h>

enum struct TilemapID: unsigned int {
    NONE = 0,
    BLOCKS,
    OUTLINE,
    NB_TILEMAPS
};

// TODO: this data should be elsewhere
size_t get_tiles_nb(TilemapID id);

#endif // TILEMAP_ENUMS_H
