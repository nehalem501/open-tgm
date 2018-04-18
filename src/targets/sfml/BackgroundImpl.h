/* BackgroundImpl.h - SFML */

#ifndef BACKGROUND_SFML_H
#define BACKGROUND_SFML_H

#include <vector>
#include <list>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
#include <core/Background.h>

/* Used by BackgroundSFML to divide the background image in multiple sprites
   if the maximum texture size of the GPU is smaller than the background's size */
class BackgroundSprite {
    public:
        float x, y;
        sf::Sprite sprite;
};

class BackgroundImpl : public Core::Background, public sf::Drawable {
    public:
        void init_graphics();
        void resize();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        std::list<sf::Texture> textures;
        std::list<BackgroundSprite> sprites;
        sf::Vector2u imageSize;
        sf::Image image;
        sf::VertexArray m_vertices;
};

#endif
