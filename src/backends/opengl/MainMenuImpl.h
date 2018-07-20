/* MainMenuImpl.h - OpenGL */

#ifndef MAIN_MENU_OPENGL_H
#define MAIN_MENU_OPENGL_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
