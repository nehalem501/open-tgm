/* BaseText.h */

#ifndef BASE_TEXT_H
#define BASE_TEXT_H

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
        CYAN
    };
}

class BaseText {
    public:
        int8_t m_pos_x, m_pos_y, m_color;
        bool m_has_changed;
        unsigned int m_length;
        const char *m_str;

        BaseText();
        BaseText(int8_t pos_x, int8_t pos_y);
        void update_text(const char *new_str);
        void update_pos(int8_t pos_x, int8_t pos_y);
};

#endif
