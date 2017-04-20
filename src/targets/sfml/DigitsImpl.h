/* DigitsImpl.h -SFML */

#ifndef DIGITS_SFML_H
#define DIGITS_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseDigits.h>

class DigitsImpl : public BaseDigits, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        sf::VertexArray m_vertices;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
