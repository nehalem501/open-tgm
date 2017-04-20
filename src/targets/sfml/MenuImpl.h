/* MenuImpl.h - SFML */

#ifndef MENU_SFML_H
#define MENU_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseMenu.h>

class MenuImpl : public BaseMenu, public sf::Drawable {
    public:
        void initGraphics();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
};

#endif
