/* LabelsImpl.h - SFML */

#ifndef LABELS_SFML_H
#define LABELS_SFML_H

#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseLabels.h>

class LabelsImpl : public BaseLabels, public sf::Drawable {
    private:
        float posX, posY, displaySize;
        unsigned int length;
        sf::VertexArray m_vertices;
        sf::Texture m_font;
        std::vector<std::string> str;
        std::vector<sf::Vector2f> positions;

    public:
        void initGraphics();
        void updateSize(float gamePosX, float gamePosY, float displayTileSize);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
