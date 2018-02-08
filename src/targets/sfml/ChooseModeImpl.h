/* ChooseModeImpl.h - SFML */

#ifndef CHOOSE_MODE_SFML_H
#define CHOOSE_MODE_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/ChooseMode.h>

class ChooseModeImpl : public Core::ChooseMode, public sf::Drawable {
    public:
        void init_graphics();
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
