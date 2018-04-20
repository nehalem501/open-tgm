/* MainMenuImpl.h - Dummy */

#ifndef MAIN_MENU_DUMMY_H
#define MAIN_MENU_DUMMY_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
