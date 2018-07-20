/* HomeImpl.h - OpenGL */

#ifndef HOME_OPENGL_H
#define HOME_OPENGL_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
