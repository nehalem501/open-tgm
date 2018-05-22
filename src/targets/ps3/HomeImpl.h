/* HomeImpl.h - PS3 */

#ifndef HOME_PS3_H
#define HOME_PS3_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
