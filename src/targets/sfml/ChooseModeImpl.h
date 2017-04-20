/* ChooseModeImpl.h - SFML */

#ifndef CHOOSE_MODE_SFML_H
#define CHOOSE_MODE_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseChooseMode.h>

class ChooseModeImpl : public BaseChooseMode, public sf::Drawable {
    public:
        void initGraphics();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);

    private:
        sf::Sprite m_logo, m_start;
        sf::Texture m_logo_tex, m_start_tex;
};

#endif
