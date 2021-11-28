/* Tilemap.h - GPU */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <stddef.h>
#include <Shapes.h>
#include <Debug.h>
#include "Reloadable.h"
#include "TilemapData.h"
#include "Texture.h"
#include "VertexArray.h"

template <size_t N>
class Tilemap : public Reloadable {
    public:
        Tilemap(
            Position position, // TODO
            const tiles_t *tiles,
            const ColorRGBA& c,
            unsigned int width,
            unsigned int height,
            TextureID texture) :
                m_tiles(tiles),
                m_width(width),
                m_height(height),
                m_vertex_array(texture) {
            printd("Tilemap<" << N << "> constructor");

            register_reloadable(this);

            m_vertex_array.vertices[0].x(position.x);
            m_vertex_array.vertices[0].y(position.y);

            /*for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile(i, j, tiles[i + j * m_width] & 0xFF); // TODO
                    tile_position(i, j);
                }
            }*/

            color(c);

            for (unsigned int i = width * height * 4; i < N * 4; i++) {
                m_vertex_array.vertices[i].clear();
            }
        }

        virtual void refresh() {
            const TextureID id = m_vertex_array.m_implementation.m_texture;
            const TilemapData& data = get_tilemap_data(id);
            for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile_position(i, j);
                    tile(data, i + j * m_width);
                }
            }
        }

        inline void color(const ColorRGBA& color) {
            for (unsigned int i = 0; i < m_width * m_height * 4; i++) {
                m_vertex_array.vertices[i].color(color);
            }
        }

        inline void position(const Position& position) {
            m_vertex_array.move(
                ((float) position.x) - m_vertex_array.vertices[0].x(),
                ((float) position.y) - m_vertex_array.vertices[0].y());
        }

        void update(const tiles_t *tiles) {
            m_tiles = tiles;
            const TextureID id = m_vertex_array.m_implementation.m_texture;
            const TilemapData& data = get_tilemap_data(id);
            for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile(data, i + j * m_width);
                }
            }
        }

        inline void tile(const TilemapData& data, const size_t i) {
            const TileData& tile_data = data.get(m_tiles[i] & 0xFF);

            const size_t index = i * 4;

            m_vertex_array.vertices[index].tex_coords(tile_data.tex_coord_top_left);
            m_vertex_array.vertices[index + 1].tex_coords(tile_data.tex_coord_bottom_left);
            m_vertex_array.vertices[index + 2].tex_coords(tile_data.tex_coord_bottom_right);
            m_vertex_array.vertices[index + 3].tex_coords(tile_data.tex_coord_top_right);
        }

        inline void tile_position(unsigned int tile_x, unsigned int tile_y) {
            const float tile_size_gpu = tile_size;
            const size_t index = (tile_x + tile_y * m_width) * 4;

            const float x = m_vertex_array.vertices[0].x();
            const float y = m_vertex_array.vertices[0].y();

            m_vertex_array.vertices[index].x(x + tile_x * tile_size_gpu);
            m_vertex_array.vertices[index].y(y + tile_y * tile_size_gpu);

            m_vertex_array.vertices[index + 1].x(x + tile_x * tile_size_gpu);
            m_vertex_array.vertices[index + 1].y(y + (tile_y + 1.0f) * tile_size_gpu);

            m_vertex_array.vertices[index + 2].x(x + (tile_x + 1.0f) * tile_size_gpu);
            m_vertex_array.vertices[index + 2].y(y + (tile_y + 1.0f) * tile_size_gpu);

            m_vertex_array.vertices[index + 3].x(x + (tile_x + 1.0f) * tile_size_gpu);
            m_vertex_array.vertices[index + 3].y(y + tile_y * tile_size_gpu);
        }

        void render() const { m_vertex_array.render(); }

        #ifdef RESIZABLE
        void resize(const Position& position) {
            m_vertex_array.vertices[0].x(position.x);
            m_vertex_array.vertices[0].y(position.y);

            for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile_position(i, j);
                }
            }
        }
        #endif

    private:
        //Position m_position;
        const tiles_t* m_tiles;
        unsigned int m_width, m_height;
        VertexArray2D<N * 4> m_vertex_array;

        //gpu_float_t m_tile_size;
        //tiles_t m_row_size;
};

#endif // TILEMAP_H
