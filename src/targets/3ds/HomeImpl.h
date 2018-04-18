/* HomeImpl.h - 3DS */

#ifndef HOME_3DS_H
#define HOME_3DS_H

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
