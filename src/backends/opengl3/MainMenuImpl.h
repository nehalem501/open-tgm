/* MainMenuImpl.h - OpenGL3 */

#ifndef MAIN_MENU_OPENGL3_H
#define MAIN_MENU_OPENGL3_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
