/* MenuImpl.h - GBA */

#ifndef MENU_GBA_H
#define MENU_GBA_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void initGraphics();
        void draw() const;
};

#endif
