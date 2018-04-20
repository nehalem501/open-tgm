/* MainMenuImpl.h - SFML */

#ifndef MAIN_MENU_SFML_H
#define MAIN_MENU_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/MainMenu.h>

class MainMenuImpl : public Core::MainMenu, public sf::Drawable {
    public:
        void init_graphics();
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
