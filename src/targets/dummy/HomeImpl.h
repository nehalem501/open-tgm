/* HomeImpl.h - Dummy */

#ifndef HOME_DUMMY_H
#define HOME_DUMMY_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void initGraphics();
        void draw() const;
};

#endif
