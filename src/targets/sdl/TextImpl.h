/* TextImpl.h - SDL */

#ifndef TEXT_SDL_H
#define TEXT_SDL_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <core/Text.h>

class TextImpl : public Core::Text {
    public:
        void init_graphics();
        void update_graphics();
        void update_color(int8_t color);
        void draw() const;
};

#endif
