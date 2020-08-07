/* ChooseModeImpl.h - PSP */

#ifndef CHOOSE_MODE_PSP_H
#define CHOOSE_MODE_PSP_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
