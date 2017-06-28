/* HomeImpl.h - GBA */

#ifndef HOME_GBA_H
#define HOME_GBA_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void initGraphics();
        void draw() const;
};

#endif
