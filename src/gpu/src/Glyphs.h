/* Glyphs.h - GPU */

#ifndef GLYPHS_H
#define GLYPHS_H

#include <stddef.h>
#include <Position.h>
#include <Debug.h>
#include <iostream>
#include "Reloadable.h"
#include "Vertex.h"
#include "Glyph.h"
#include "Texture.h"
#include "VertexArray.h"
#include "GpuFont.h"
#include "FontManager.h"
#include "GPU.h"

/* Forward declarations to avoid dependency hell */
class Text;

//const Glyph* get_glyph_array(Font font);
//void clear_glyph_data(TextureID id);
//void set_glyph_data(TextureID id, uint8_t c, const Glyph& data);

void init_glyphs(
    Vertex2D *vertices,
    const char *text,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    int text_color,
    float texture_width,
    float texture_height,
    int texture_tile_size,
    unsigned int length,
    size_t size);

void set_color(Vertex2D *vertices, const ColorRGBA& new_color, size_t size);
void set_position(Vertex2D *vertices, const Position& position, size_t size);
void position_glyphs_from_string(
    Vertex2D *vertices,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    const unsigned char* str,
    float texture_width,
    float texture_height,
    int texture_tile_size,
    size_t length,
    size_t size);

template <size_t N>
class Glyphs : public Reloadable {
    public:
        Glyphs(const char *text, Position position, Layout layout, int text_color, unsigned int length, GpuFontID font) :
                m_text_str(text),
                m_length(length),
                m_position(position),
                m_layout(layout),
                m_font(font),
                m_glyphs(FontManager::get().get_font(font).get_glyphs()),
                m_vertex_array(font_to_texture(font))
        {
            printd(DebugCategory::GPU_GLYPHS, "Typeface<", N, "> constructor");

            //register_reloadable(this); // TODO
            const Texture& t = GPU::get_current().get_texture(font_to_texture(m_font));
            init_glyphs(
                m_vertex_array.vertices,
                text,
                m_glyphs,
                position,
                layout,
                text_color,
                t.width(),
                t.height(),
                t.texture_tile_size(),
                length,
                N);
        }

        virtual void refresh() {
            position_glyphs(
                m_position,
                m_layout,
                m_text_str,
                m_length);
        }

        inline void font(const GpuFontID& new_font) {
            m_font = new_font;
            m_glyphs = FontManager::get().get_font(m_font).get_glyphs();
            m_vertex_array.texture(font_to_texture(m_font));
            position_glyphs(
                m_position,
                m_layout,
                m_text_str,
                m_length);
        }

        inline void color(const ColorRGBA& new_color) {
            set_color(m_vertex_array.vertices, new_color, N);
        }

        inline void position(const Position& position) {
            m_position = position;
            set_position(m_vertex_array.vertices, position, N);
        }

        void position_glyphs(
            const Position &position,
            Layout layout,
            const char* str,
            unsigned int length)
        {
            m_position = position;
            m_text_str = str;
            m_length = length;
            m_layout = layout;
            std::cout << "font: " << (int) m_font << std::endl;
            const Texture& t = GPU::get_current().get_texture(font_to_texture(m_font));
            position_glyphs_from_string(
                m_vertex_array.vertices,
                m_glyphs,
                m_position,
                m_layout,
                (const unsigned char*) m_text_str,
                t.width(),
                t.height(),
                t.texture_tile_size(),
                (size_t) m_length,
                N);
        }

        void update_text(const char* str, unsigned int length) {
            m_text_str = str;
            m_length = length;
            const Texture& t = GPU::get_current().get_texture(font_to_texture(m_font));
            position_glyphs_from_string(
                m_vertex_array.vertices,
                m_glyphs,
                m_position,
                m_layout,
                (const unsigned char*) m_text_str,
                t.width(),
                t.height(),
                t.texture_tile_size(),
                (size_t) m_length,
                N);
        }

        inline void render() const { m_vertex_array.render(); };

        #ifdef RESIZABLE
        void resize(const Position &position, Layout layout) {
            // TODO
            printd(DebugCategory::GPU_GLYPHS, "Glyphs: Resize: position: (old=", m_position, ", new=", position, ")");

            position_glyphs(
                position,
                layout,
                m_text_str,
                m_length);
        }
        #endif // RESIZABLE

    private:
        const char *m_text_str;
        unsigned int m_length;
        Position m_position;
        Layout m_layout;
        GpuFontID m_font;

        const Glyph *m_glyphs;
        VertexArray2D<N * 4> m_vertex_array;
};

#endif // GLYPHS_H
