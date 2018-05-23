/* HomeImpl.h - PSVita */

#ifndef HOME_PSVITA_H
#define HOME_PSVITA_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
