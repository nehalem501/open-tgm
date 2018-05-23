/* MainMenuImpl.h - PSVita */

#ifndef MAIN_MENU_PSVITA_H
#define MAIN_MENU_PSVITA_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
