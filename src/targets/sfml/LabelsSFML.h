/* LabelsSFML.h */

#ifndef LABELS_H
#define LABELS_H

#ifdef TARGET_SFML
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#endif

#ifdef TARGET_SFML
class Labels : public sf::Drawable {
#else
class Labels {
#endif
    public:
        void initGraphics();

    #ifdef TARGET_SFML
        float posX, posY, displaySize;
        unsigned int length;
        sf::VertexArray m_vertices;
        sf::Texture m_font;
        std::vector<std::string> str;
        std::vector<sf::Vector2f> positions;

        void init(std::vector<std::string> text, std::vector<sf::Vector2f> textPos);
        void updateSize(float gamePosX, float gamePosY, float displayTileSize);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    #endif
    #ifdef TARGET_DUMMY
    public:
        void init(); //TODO
        void draw();
    private:
    #endif
};
#endif
