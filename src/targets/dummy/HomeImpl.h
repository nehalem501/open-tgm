/* HomeImpl.h - Dummy */

#ifndef HOME_DUMMY_H
#define HOME_DUMMY_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
