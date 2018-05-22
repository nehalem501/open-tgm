/* MainMenuImpl.h - PSX */

#ifndef MAIN_MENU_PSX_H
#define MAIN_MENU_PSX_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
