/* BackgroundImpl.h - PSP */

#ifndef BACKGROUND_PSP_H
#define BACKGROUND_PSP_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void initGraphics();
        void draw() const;
};

#endif
