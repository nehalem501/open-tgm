/* DigitsSFML.h */

#ifndef DIGITS_SFML_H
#define DIGITS_SFML_H

#include <stdint.h>
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseDigits.h>

class DigitsSFML : public sf::Drawable, public BaseDigits {
    public:
        sf::VertexArray m_vertices;
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
