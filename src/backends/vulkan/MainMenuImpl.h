/* MainMenuImpl.h - Vulkan */

#ifndef MAIN_MENU_VULKAN_H
#define MAIN_MENU_VULKAN_H

#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu {
    public:
        void init_graphics();
        void draw() const;
};

#endif
