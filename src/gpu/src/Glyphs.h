/* Glyphs.h - GPU */

#ifndef GLYPHS_H
#define GLYPHS_H

#include <stddef.h>
#include <Position.h>
#include <Debug.h>
#include "Reloadable.h"
#include "Vertex.h"
#include "Glyph.h"
#include "Texture.h"
#include "VertexArray.h"

/* Forward declarations to avoid dependency hell */
class Text;

typedef unsigned int Font;

namespace Fonts {
    enum {
        UI_FONT = 0,
        LABEL_FONT,
        DIGITS_FONT,
        NB_FONTS
    };
}

ColorRGBA text_color_to_gpu_color(int color);
TextureID font_to_texture(Font font);
const Glyph* get_glyph_array(Font font);
void clear_glyph_data(TextureID id);
void set_glyph_data(TextureID id, uint8_t c, const Glyph& data);

void init_glyphs(
    Vertex2D *vertices,
    const char *text,
    const Glyph *glyphs,
    const Position &position,
    Layout layout,
    int text_color,
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
    size_t length,
    size_t size);

template <size_t N>
class Glyphs : public Reloadable {
    public:
        Glyphs(const char *text, Position position, Layout layout, int text_color, unsigned int length, Font font) :
                m_text_str(text),
                m_length(length),
                m_position(position),
                m_layout(layout),
                m_glyphs(get_glyph_array(font)), // TODO
                m_vertex_array(font_to_texture(font))
        {
            printd("Typeface<" << N << "> constructor");

            register_reloadable(this);
            init_glyphs(m_vertex_array.vertices, text, m_glyphs, position, layout, text_color, length, N);
        }

        virtual void refresh() {
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
            position_glyphs_from_string(
                m_vertex_array.vertices,
                m_glyphs,
                m_position,
                m_layout,
                (const unsigned char*) m_text_str,
                (size_t) m_length,
                N);
        }

        inline void render() const { m_vertex_array.render(); };

        #ifdef RESIZABLE
        void resize() {
            // TODO
        }
        #endif

    private:
        const char *m_text_str;
        unsigned int m_length;
        Position m_position;
        Layout m_layout;

        const Glyph *m_glyphs;
        VertexArray2D<N * 4> m_vertex_array;
};

#endif // GLYPHS_H
