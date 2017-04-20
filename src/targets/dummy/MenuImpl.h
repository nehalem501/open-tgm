/* MenuImpl.h - Dummy */

#ifndef MENU_DUMMY_H
#define MENU_DUMMY_H

#include <common/BaseMenu.h>

class MenuImpl : public BaseMenu {
    public:
        void initGraphics();
        void draw() const;
};

#endif
