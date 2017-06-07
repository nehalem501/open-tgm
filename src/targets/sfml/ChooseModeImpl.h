/* ChooseModeImpl.h - SFML */

#ifndef CHOOSE_MODE_SFML_H
#define CHOOSE_MODE_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseChooseMode.h>

class ChooseModeImpl : public BaseChooseMode, public sf::Drawable {
    public:
        void initGraphics();
        void updateSize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
