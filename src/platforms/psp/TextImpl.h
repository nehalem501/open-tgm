/* TextImpl.h - PSP */

#ifndef TEXT_PSP_H
#define TEXT_PSP_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <stdint.h>
#include <GlobalPSP.h>
#include <core/Text.h>

#define TEXT_LEN_LIMIT 32

class TextImpl : public Core::Text {
    public:
        void init_graphics();
        void update_graphics();
        void update_vertices();
        void update_color(int8_t color);
        void draw() const;
    private:
        quad m_quads[TEXT_LEN_LIMIT];
        unsigned int m_quads_len;
};

#endif
