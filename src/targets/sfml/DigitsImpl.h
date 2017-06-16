/* DigitsImpl.h - SFML */

#ifndef DIGITS_SFML_H
#define DIGITS_SFML_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Digits.h>

class DigitsImpl : public Core::Digits, public sf::Drawable {
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
