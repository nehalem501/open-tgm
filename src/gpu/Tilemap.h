/* Tilemap.h - GPU */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <stddef.h>
#include "VertexArray.h"

template <size_t N>
class Tilemap {
    private:
        Position m_position;
        VertexArray2D<N * 4> m_vertex_array;
};

#endif // TILEMAP_H
