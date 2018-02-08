/* GameImpl.h - SFML */

#ifndef GAME_SFML_H
#define GAME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Game.h>

class GameImpl : public Core::Game, public sf::Drawable {
    public:
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
