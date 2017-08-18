/* MenuImpl.h - 3DS */

#ifndef MENU_3DS_H
#define MENU_3DS_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void initGraphics();
        void draw() const;
};

#endif
