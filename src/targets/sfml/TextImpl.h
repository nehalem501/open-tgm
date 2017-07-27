/* TextImpl.h - SFML */

#ifndef TEXT_SFML_H
#define TEXT_SFML_H

/* Forward declarations to avoid dependency hell */
class StackImpl;
typedef StackImpl Stack;

#include <stdint.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/Text.h>

class TextImpl : public Core::Text, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        void updateSize();
        void update_color(int8_t color);
        void assign_color();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        void updateVertices();
        sf::VertexArray m_vertices;
};

#endif
