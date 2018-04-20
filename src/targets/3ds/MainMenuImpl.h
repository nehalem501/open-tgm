/* MainMenuImpl.h - 3DS */

#ifndef MAIN_MENU_3DS_H
#define MAIN_MENU_3DS_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
