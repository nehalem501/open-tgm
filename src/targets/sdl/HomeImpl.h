/* HomeImpl.h - SDL */

#ifndef HOME_SDL_H
#define HOME_SDL_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
