/* HomeImpl.h - 3DS */

#ifndef HOME_3DS_H
#define HOME_3DS_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void initGraphics();
        void draw() const;
};

#endif
