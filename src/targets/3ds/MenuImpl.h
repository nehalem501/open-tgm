/* MenuImpl.h - 3DS */

#ifndef MENU_3DS_H
#define MENU_3DS_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
