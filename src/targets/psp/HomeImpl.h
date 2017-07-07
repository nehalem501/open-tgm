/* HomeImpl.h - PSP */

#ifndef HOME_PSP_H
#define HOME_PSP_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void initGraphics();
        void draw() const;
};

#endif
