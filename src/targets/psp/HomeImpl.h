/* HomeImpl.h - PSP */

#ifndef HOME_PSP_H
#define HOME_PSP_H

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
