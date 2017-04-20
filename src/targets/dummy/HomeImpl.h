/* HomeImpl.h - Dummy */

#ifndef HOME_DUMMY_H
#define HOME_DUMMY_H

#include <common/BaseHome.h>

class HomeImpl : public BaseHome {
    public:
        void initGraphics();
        void draw() const;
};

#endif
