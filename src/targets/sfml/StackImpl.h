/* StackImpl.h - SFML */

#ifndef STACK_SFML_H
#define STACK_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Stack.h>

class StackImpl : public Core::Stack, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize();

    private:
        sf::VertexArray m_vertices;
        sf::VertexArray m_vertices_outline;
        void assign_tile(int tile, unsigned char rgb, unsigned char alpha, sf::Vertex* quad);
};

#endif
