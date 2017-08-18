/* BackgroundImpl.h - 3DS */

#ifndef BACKGROUND_3DS_H
#define BACKGROUND_3DS_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void initGraphics();
        void draw() const;
};

#endif
