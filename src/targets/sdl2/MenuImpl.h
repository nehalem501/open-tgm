/* MenuImpl.h - SDL2 */

#ifndef MENU_SDL2_H
#define MENU_SDL2_H

#include <core/Menu.h>

class MenuImpl : public Core::Menu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
