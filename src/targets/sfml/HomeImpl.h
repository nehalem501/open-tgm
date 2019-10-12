/* HomeImpl.h - SFML */

#ifndef HOME_SFML_H
#define HOME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Home.h>

class HomeImpl : public Core::Home, public sf::Drawable {
    public:
        void init_graphics();
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::Sprite m_logo;
        sf::Texture m_logo_tex;
};

#endif
