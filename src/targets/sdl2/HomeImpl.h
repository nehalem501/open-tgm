/* HomeImpl.h - SDL2 */

#ifndef HOME_SDL2_H
#define HOME_SDL2_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
