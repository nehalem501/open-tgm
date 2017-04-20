/* BackgroundImpl.h - Dummy */

#ifndef BACKGROUND_DUMMY_H
#define BACKGROUND_DUMMY_H

#include <common/BaseBackground.h>

class BackgroundImpl : public BaseBackground {
    public:
        void initGraphics();
        void draw() const;
};

#endif
