/* ChooseModeImpl.h - PSX */

#ifndef CHOOSE_MODE_PSX_H
#define CHOOSE_MODE_PSX_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
