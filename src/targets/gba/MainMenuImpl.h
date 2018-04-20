/* MainMenuImpl.h - GBA */

#ifndef MAIN_MENU_GBA_H
#define MAIN_MENU_GBA_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
