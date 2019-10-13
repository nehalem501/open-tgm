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
        Text(int pos_x, int pos_y);
        Text(int pos_x, int pos_y, int color, const char *str);
        Text(Stack *stack, int pos_x, int pos_y);
        Text(Stack *stack, int pos_x, int pos_y,
             int color, const char *str);

        void position(Position position);
        void text(const char *new_str);
        void color(const int color);

    private:
        Position m_position,
        Position *m_parent;

        int m_color;
        unsigned int m_length;

        const char *m_str;

        TextImpl m_implementation;
};

#endif // TEXT_H
