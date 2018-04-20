/* MainMenuImpl.h - SDL2 */

#ifndef MAIN_MENU_SDL2_H
#define MAIN_MENU_SDL2_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
