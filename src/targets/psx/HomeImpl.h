/* HomeImpl.h - PSX */

#ifndef HOME_PSX_H
#define HOME_PSX_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
