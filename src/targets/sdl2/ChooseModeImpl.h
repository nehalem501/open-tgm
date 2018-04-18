/* ChooseModeImpl.h - SDL2 */

#ifndef CHOOSE_MODE_SDL2_H
#define CHOOSE_MODE_SDL2_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
