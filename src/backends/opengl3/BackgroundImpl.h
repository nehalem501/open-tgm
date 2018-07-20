/* BackgroundImpl.h - OpenGL3 */

#ifndef BACKGROUND_OPENGL3_H
#define BACKGROUND_OPENGL3_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
