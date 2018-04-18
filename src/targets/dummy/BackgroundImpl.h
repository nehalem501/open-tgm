/* BackgroundImpl.h - Dummy */

#ifndef BACKGROUND_DUMMY_H
#define BACKGROUND_DUMMY_H

#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void init_graphics();
        void draw() const;
};

#endif
