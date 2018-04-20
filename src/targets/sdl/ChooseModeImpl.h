/* ChooseModeImpl.h - SDL */

#ifndef CHOOSE_MODE_SDL_H
#define CHOOSE_MODE_SDL_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
