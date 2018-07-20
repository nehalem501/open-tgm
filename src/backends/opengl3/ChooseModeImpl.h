/* ChooseModeImpl.h - OpenGL3 */

#ifndef CHOOSE_MODE_OPENGL3_H
#define CHOOSE_MODE_OPENGL3_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
