/* ChooseModeImpl.h - Dummy */

#ifndef CHOOSE_MODE_DUMMY_H
#define CHOOSE_MODE_DUMMY_H

#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode {
    public:
        void init_graphics();
        void draw() const;
};

#endif
