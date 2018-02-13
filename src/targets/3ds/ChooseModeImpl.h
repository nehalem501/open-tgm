/* ChooseModeImpl.h - 3DS */

#ifndef CHOOSE_MODE_3DS_H
#define CHOOSE_MODE_3DS_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
