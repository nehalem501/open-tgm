/* MainMenuImpl.h - SDL */

#ifndef MAIN_MENU_SDL_H
#define MAIN_MENU_SDL_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
