/* StackImpl.h - SFML */

#ifndef STACK_SFML_H
#define STACK_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseStack.h>

class StackImpl : public BaseStack, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);

    private:
        sf::VertexArray m_vertices;
        sf::VertexArray m_vertices_outline;
};

#endif
