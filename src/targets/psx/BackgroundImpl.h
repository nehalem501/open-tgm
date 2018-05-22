/* BackgroundImpl.h - PSX */

#ifndef BACKGROUND_PSX_H
#define BACKGROUND_PSX_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
