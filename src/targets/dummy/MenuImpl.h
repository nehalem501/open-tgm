/* MenuImpl.h - Dummy */

#ifndef MENU_DUMMY_H
#define MENU_DUMMY_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void initGraphics();
        void draw() const;
};

#endif
