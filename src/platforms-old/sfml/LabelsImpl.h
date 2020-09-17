/* LabelsImpl.h - SFML */

#ifndef LABELS_SFML_H
#define LABELS_SFML_H

#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <core/Labels.h>

class LabelsImpl : public Core::Labels, public sf::Drawable {
    private:
        unsigned int length;
        sf::VertexArray m_vertices;
        std::vector<std::string> str;
        std::vector<sf::Vector2f> positions;

    public:
        void init_graphics(Stack *stack);
        void resize(Stack *stack);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
