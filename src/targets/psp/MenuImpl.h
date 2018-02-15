/* MenuImpl.h - PSP */

#ifndef MENU_PSP_H
#define MENU_PSP_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
