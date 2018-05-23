/* BackgroundImpl.h - PSVita */

#ifndef BACKGROUND_PSVITA_H
#define BACKGROUND_PSVITA_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
