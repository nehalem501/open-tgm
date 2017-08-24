/* TextImpl.h - 3DS */

#ifndef TEXT_3DS_H
#define TEXT_3DS_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <stdint.h>
#include "Global3DS.h"
#include <core/Text.h>

#define TEXT_LEN_LIMIT 64

class TextImpl : public Core::Text {
    public:
        void initGraphics();
        void updateGraphics();
        void update_vertices();
        void update_color(int8_t color);
        void draw() const;
    private:
        quad m_quads[TEXT_LEN_LIMIT];
        unsigned int m_quads_len;
};

#endif
