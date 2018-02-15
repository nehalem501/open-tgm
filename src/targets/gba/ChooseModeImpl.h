/* ChooseModeImpl.h - GBA */

#ifndef CHOOSE_MODE_GBA_H
#define CHOOSE_MODE_GBA_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
