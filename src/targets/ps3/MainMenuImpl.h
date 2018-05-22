/* MainMenuImpl.h - PS3 */

#ifndef MAIN_MENU_PS3_H
#define MAIN_MENU_PS3_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
