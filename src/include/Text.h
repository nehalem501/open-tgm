/* Text.h */

#ifndef TEXT_H
#define TEXT_H

#include <Position.h>
#include <Coordinates.h>
#include <TextImpl.h>

namespace TextColor {
    enum {
        NONE = 0,
        WHITE = 0,
        RED,
        GREEN,
        BLUE,
        YELLOW,
        MAGENTA,
        CYAN,
        ORANGE,
        TRANSPARENT
    };
}

class Text {
    public:
        Text();

        Text(
            const Position& parent,
            const Coordinates& coordinates,
            Layout layout = Layouts::NONE
        );

        Text(
            const Position& parent,
            const Coordinates& coordinates,
            Layout layout,
            int color,
            const char *str);

        void draw() const;

        #ifdef RESIZABLE
        void resize(const Position& parent) {
            m_position = m_coordinates.to_position() + parent;
            m_implementation.resize();
        }
        #endif

        void position(const Coordinates& coordinates, const Position& parent);
        void position(
            const Coordinates& coordinates,
            const Position& parent,
            Layout layout);

        void text(const char *new_str);
        void color(int color);

        inline const Position& position() const { return m_position; };
        inline Layout layout() const { return m_layout; };
        inline unsigned int length() const { return m_length; };
        inline const char* text() const { return m_str; };
        inline int color() const { return m_color; };

    private:
        Coordinates m_coordinates;
        Position m_position;

        Layout m_layout;

        int m_color;
        unsigned int m_length;

        const char *m_str;

        TextImpl m_implementation;
};

#endif // TEXT_H
