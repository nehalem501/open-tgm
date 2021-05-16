/* Glyphs.h - GPU */

#ifndef GLYPHS_H
#define GLYPHS_H

#include <stddef.h>
#include <Position.h>
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
        DIGITS_FONT
    };
}

ColorRGBA text_color_to_gpu_color(int color);
TextureID font_to_texture(Font font);
const Glyph* get_glyph_array(Font font);

void init_glyphs_text(
    Vertex2D *vertices,
    const Text& text,
    const Glyph *glyphs,
    size_t size);
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
class Glyphs {
    public:
        Glyphs(const Text &text, Font font) :
                m_glyphs(get_glyph_array(font)), // TODO
                m_vertex_array(font_to_texture(font)) {
            #ifdef DEBUG
            print("Typeface<%d> constructor\n", (int) N);
            #endif

            init_glyphs_text(m_vertex_array.vertices, text, m_glyphs, N);
        }

        Glyphs(const char *text, Position position, Layout layout, int text_color, unsigned int length, Font font) :
                m_glyphs(get_glyph_array(font)), // TODO
                m_vertex_array(font_to_texture(font)) {
            #ifdef DEBUG
            print("Typeface<%d> constructor\n", (int) N);
            #endif

            init_glyphs(m_vertex_array.vertices, text, m_glyphs, position, layout, text_color, length, N);
        }

        void color(const ColorRGBA& new_color) {
            set_color(m_vertex_array.vertices, new_color, N);
        }

        void position(const Position& position) {
            set_position(m_vertex_array.vertices, position, N);
        }

        void position_glyphs(
            const Position &position,
            Layout layout,
            const unsigned char* str,
            unsigned int length) {

            position_glyphs_from_string(
                m_vertex_array.vertices,
                m_glyphs,
                position,
                layout,
                str,
                (size_t) length,
                N);
        }

        inline void render() const { m_vertex_array.render(); };

        #ifdef RESIZABLE
        void resize() {
            // TODO
        }
        #endif

    private:
        //Position m_position;
        const Glyph *m_glyphs;
        VertexArray2D<N * 4> m_vertex_array;
};

#endif // GLYPHS_H
