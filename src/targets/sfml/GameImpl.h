/* GameImpl.h - SFML */

#ifndef GAME_SFML_H
#define GAME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseGame.h>

class GameImpl : public BaseGame, public sf::Drawable {
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
};

#endif
