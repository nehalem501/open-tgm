/* BackgroundImpl.h - OpenGL */

#ifndef BACKGROUND_OPENGL_H
#define BACKGROUND_OPENGL_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
