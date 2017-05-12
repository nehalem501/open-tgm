/* DigitsImpl.h - SFML */

#ifndef DIGITS_SFML_H
#define DIGITS_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <common/BaseDigits.h>

class DigitsImpl : public BaseDigits, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics(Stack *stack);
        void updateSize(Stack *stack);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        void updateVertices(Stack *stack);
        sf::VertexArray m_vertices;
};

#endif
