/* BackgroundImpl.h - GBA */

#ifndef BACKGROUND_GBA_H
#define BACKGROUND_GBA_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void initGraphics();
        void draw() const;
};

#endif
