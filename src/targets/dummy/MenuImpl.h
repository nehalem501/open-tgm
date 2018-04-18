/* MenuImpl.h - Dummy */

#ifndef MENU_DUMMY_H
#define MENU_DUMMY_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
