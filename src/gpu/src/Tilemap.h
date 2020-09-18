/* Tilemap.h - GPU */

#ifndef TILEMAP_H
#define TILEMAP_H

#include <stddef.h>
#include <Shapes.h>
#include "Texture.h"
#include "VertexArray.h"

template <size_t N>
class Tilemap {
    public:
        Tilemap(
            Position position, // TODO
            const tiles_t *tiles,
            const ColorRGBA& c,
            unsigned int width,
            unsigned int height,
            gpu_float_t texture_width, // TODO
            gpu_float_t texture_height,
            //gpu_float_t tile_size,
            tiles_t row_size,
            TextureID texture) :
                m_width(width),
                m_height(height),
                m_vertex_array(texture),
                m_texture_width(texture_width),
                m_texture_height(texture_height),
                //m_tile_size(tile_size),
                m_row_size(row_size) {
            #ifdef DEBUG
            print("Tilemap<%d> constructor\n", (int) N);
            #endif

            m_vertex_array.vertices[0].x = position.x;
            m_vertex_array.vertices[0].y = position.y;

            for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile(i, j, tiles[i + j * m_width] & 0xFF); // TODO
                    tile_position(i, j);
                }
            }

            color(c);

            for (unsigned int i = width * height * 4; i < N * 4; i++) {
                m_vertex_array.vertices[i].x = 0.0f;
                m_vertex_array.vertices[i].y = 0.0f;

                m_vertex_array.vertices[i].u = 0.0f;
                m_vertex_array.vertices[i].v = 0.0f;

                m_vertex_array.vertices[i].r = 0.0f;
                m_vertex_array.vertices[i].g = 0.0f;
                m_vertex_array.vertices[i].b = 0.0f;
                m_vertex_array.vertices[i].a = 0.0f;
            }
        }

        inline void color(const ColorRGBA& color) {
            for (unsigned int i = 0; i < m_width * m_height * 4; i++) {
                m_vertex_array.vertices[i].color(color);
            }
        }

        inline void position(const Position& position) {
            m_vertex_array.move(
                ((gpu_float_t) position.x) - m_vertex_array.vertices[0].x,
                ((gpu_float_t) position.y) - m_vertex_array.vertices[0].y);
        }

        void update(const tiles_t *tiles) {
            for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile(i, j, tiles[i + j * m_width] & 0xFF); // TODO
                }
            }
        }

        inline void tile(
            unsigned int tile_x,
            unsigned int tile_y,
            tiles_t tile) {

            const gpu_float_t tex_x = tile % m_row_size;
            const gpu_float_t tex_y = tile / m_row_size;
            const gpu_float_t u = tex_x * tile_size;
            const gpu_float_t v = tex_y * tile_size;

            const unsigned int index = (tile_x + tile_y * m_width) * 4;

            m_vertex_array.vertices[index].u = u / m_texture_width; // TODO
            m_vertex_array.vertices[index].v = v / m_texture_height; // TODO

            m_vertex_array.vertices[index + 1].u = u / m_texture_width; // TODO
            m_vertex_array.vertices[index + 1].v = (v + tile_size) / m_texture_height; // TODO

            m_vertex_array.vertices[index + 2].u = (u + tile_size) / m_texture_width; // TODO
            m_vertex_array.vertices[index + 2].v = (v + tile_size) / m_texture_height; // TODO

            m_vertex_array.vertices[index + 3].u = (u + tile_size) / m_texture_width; // TODO
            m_vertex_array.vertices[index + 3].v = v / m_texture_height; // TODO
        }

        inline void tile_position(unsigned int tile_x, unsigned int tile_y) {
            const unsigned int index = (tile_x + tile_y * m_width) * 4;

            const gpu_float_t x = m_vertex_array.vertices[0].x;
            const gpu_float_t y = m_vertex_array.vertices[0].y;

            m_vertex_array.vertices[index].x = x + tile_x * tile_size;
            m_vertex_array.vertices[index].y = y + tile_y * tile_size;

            m_vertex_array.vertices[index + 1].x = x + tile_x * tile_size;
            m_vertex_array.vertices[index + 1].y = y + (tile_y + 1.0f) * tile_size;

            m_vertex_array.vertices[index + 2].x = x + (tile_x + 1.0f) * tile_size;
            m_vertex_array.vertices[index + 2].y = y + (tile_y + 1.0f) * tile_size;

            m_vertex_array.vertices[index + 3].x = x + (tile_x + 1.0f) * tile_size;
            m_vertex_array.vertices[index + 3].y = y + tile_y * tile_size;
        }

        void render() const { m_vertex_array.render(); }

        #ifdef RESIZABLE
        void resize() {
            for (unsigned int i = 0; i < m_width; i++) {
                for (unsigned int j = 0; j < m_height; j++) {
                    tile_position(i, j);
                }
            }
        }
        #endif

    private:
        //Position m_position;
        unsigned int m_width, m_height;
        VertexArray2D<N * 4> m_vertex_array;

        gpu_float_t m_texture_width; // TODO
        gpu_float_t m_texture_height;
        //gpu_float_t m_tile_size;
        tiles_t m_row_size;
};

#endif // TILEMAP_H
