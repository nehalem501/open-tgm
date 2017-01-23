/* background.h */

#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "global.h"

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <list>
class BackgroundSprite {
    public:
        float x, y;
        sf::Sprite sprite;
};
#endif

#ifdef TARGET_PSP
#include "glib2d.h"
#endif

#ifdef TARGET_SFML
class Background : public sf::Drawable {
#else
class Background {
#endif
    public:
        Background();
        void initGraphics();
        void changeToOptions();
        void changeToBackground();
        
    private:
        bool options;
        
    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
    private:
        std::list<sf::Texture> textures;
        std::list<BackgroundSprite> sprites;
        sf::Vector2u imageSize;
        sf::Image image;
        sf::VertexArray m_vertices;
    #endif
    #ifdef TARGET_PSP
    public:
        void draw();
    private:
        g2dTexture* texture;
    #endif
    #ifdef TARGET_GBA
    public:
        void draw();
    private:
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};

#endif
