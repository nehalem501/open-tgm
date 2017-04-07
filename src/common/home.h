/* home.h */

#ifndef HOME_H
#define HOME_H

#include <stdint.h>

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#endif


#ifdef TARGET_SFML
class Home : public sf::Drawable {
#else
class Home {
#endif
    public:
        Home();
        
        void initGraphics();
        void update(int8_t *state);
        
    private:
        int8_t m_start_timer;
        
    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
    private:
        sf::Sprite m_logo, m_start;
        sf::Texture m_logo_tex, m_start_tex;
    #endif
    #ifdef TARGET_PSP
    public:
        void draw();
    private:
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
