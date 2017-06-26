/* Text.h */

#ifndef CORE_TEXT_H
#define CORE_TEXT_H

#include <stdint.h>

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
            int8_t m_pos_x, m_pos_y, m_color;
            bool m_has_changed;
            unsigned int m_length;
            const char *m_str;

            Text();
            Text(int8_t pos_x, int8_t pos_y);
            Text(int8_t pos_x, int8_t pos_y, int8_t color, const char *str);

            void update_text(const char *new_str);
            void update_pos(int8_t pos_x, int8_t pos_y);
    };
}

#endif
