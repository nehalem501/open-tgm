/* ChooseModeImpl.h - 3DS */

#ifndef CHOOSE_MODE_3DS_H
#define CHOOSE_MODE_3DS_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void initGraphics();
        void draw() const;
};

#endif
