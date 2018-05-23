/* ChooseModeImpl.h - PSVita */

#ifndef CHOOSE_MODE_PSVITA_H
#define CHOOSE_MODE_PSVITA_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
