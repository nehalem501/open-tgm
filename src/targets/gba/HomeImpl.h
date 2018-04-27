/* HomeImpl.h - GBA */

#ifndef HOME_GBA_H
#define HOME_GBA_H

#include <Text.h>
#include <core/Home.h>

class HomeImpl : public Core::Home {
    public:
        void init_graphics();
        void draw() const;
    private:
        Text m_start;
};

#endif
