/* BackgroundSFML.h */

#ifndef BACKGROUND_SFML_H
#define BACKGROUND_SFML_H

#include <vector>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseBackground.h>

/* Used by BackgroundSFML to divide the background image in multiple sprites
   if the maximum texture size of the GPU is smaller than the background's size */
class BackgroundSprite {
    public:
        float x, y;
        sf::Sprite sprite;
};

class BackgroundSFML : public sf::Drawable, public BaseBackground {
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
        
    private:
        std::list<sf::Texture> textures;
        std::list<BackgroundSprite> sprites;
        sf::Vector2u imageSize;
        sf::Image image;
        sf::VertexArray m_vertices;
};

#endif
