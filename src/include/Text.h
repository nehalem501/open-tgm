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
        Text(Position position, Position *parent);
        Text(
            Position position,
            Position *parent,
            int color,
            const char *str);

        void position(Position position);
        void text(const char *new_str);
        void color(int color);

    private:
        Position m_position;
        Position *m_parent;

        int m_color;
        unsigned int m_length;

        const char *m_str;

        TextImpl m_implementation;
};

#endif // TEXT_H
