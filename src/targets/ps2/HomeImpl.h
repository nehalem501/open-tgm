/* HomeImpl.h - PS2 */

#ifndef HOME_PS2_H
#define HOME_PS2_H

#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
};

#endif
