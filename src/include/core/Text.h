/* Text.h */

#ifndef CORE_TEXT_H
#define CORE_TEXT_H

namespace TextColor {
    enum {
        NONE = 0,
        BLACK,
        WHITE,
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

namespace Core {
    class Text {
        public:
            int m_pos_x, m_pos_y, m_color;
            bool m_has_changed;
            unsigned int m_length;
            const char *m_str;

            Text();
            Text(int pos_x, int pos_y);
            Text(int pos_x, int pos_y, int color, const char *str);

            void update_text(const char *new_str);
            void update_pos(int pos_x, int pos_y);
    };
}

#endif
