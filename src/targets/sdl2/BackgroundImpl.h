/* BackgroundImpl.h - SDL2 */

#ifndef BACKGROUND_SDL2_H
#define BACKGROUND_SDL2_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
