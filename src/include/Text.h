/* Text.h */

#ifndef TEXT_H
#define TEXT_H

#include <Position.h>
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
        Text(const Position& position, const Position& parent);
        Text(
            const Position& position,
            const Position& parent,
            int color,
            const char *str);

        void draw() const;

        void position(const Position &position, const Position& parent);
        void text(const char *new_str);
        void color(int color);

        inline const Position& position() const { return m_position; };
        inline unsigned int length() const { return m_length; };
        inline const char* text() const { return m_str; };
        inline int color() const { return m_color; };

    private:
        Position m_position;

        int m_color;
        unsigned int m_length;

        const char *m_str;

        TextImpl m_implementation;
};

#endif // TEXT_H
