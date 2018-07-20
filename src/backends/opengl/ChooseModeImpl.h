/* ChooseModeImpl.h - OpenGL */

#ifndef CHOOSE_MODE_OPENGL_H
#define CHOOSE_MODE_OPENGL_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
