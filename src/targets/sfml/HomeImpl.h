/* HomeImpl.h - SFML */

#ifndef HOME_SFML_H
#define HOME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseHome.h>

class HomeImpl : public BaseHome, public sf::Drawable {
    public:
        void initGraphics();
        void updateSize(sf::Vector2u screenSize);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Sprite m_logo, m_start;
        sf::Texture m_logo_tex, m_start_tex;
};

#endif
