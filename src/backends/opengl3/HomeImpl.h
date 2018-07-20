/* HomeImpl.h - OpenGL3 */

#ifndef HOME_OPENGL3_H
#define HOME_OPENGL3_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
