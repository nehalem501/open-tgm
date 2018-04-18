/* MenuImpl.h - SFML */

#ifndef MENU_SFML_H
#define MENU_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Menu.h>

class MenuImpl : public Core::Menu, public sf::Drawable {
    public:
        void init_graphics();
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
