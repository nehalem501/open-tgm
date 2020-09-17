/* MainMenuImpl.h - PSP */

#ifndef MAIN_MENU_PSP_H
#define MAIN_MENU_PSP_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
