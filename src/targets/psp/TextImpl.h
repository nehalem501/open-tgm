/* TextImpl.h - PSP */

#ifndef TEXT_PSP_H
#define TEXT_PSP_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <core/Text.h>

class TextImpl : public Core::Text {
    public:
        void initGraphics();
        void updateGraphics();
        void update_color(int8_t color);
        void draw() const;
};

#endif
