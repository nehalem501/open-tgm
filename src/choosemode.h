/* choosemode.h */

#ifndef CHOOSEMODE_H
#define CHOOSEMODE_H

#include <stdint.h>

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#endif


#ifdef TARGET_SFML
class ChooseMode : public sf::Drawable {
#else
class ChooseMode {
#endif
    public:
        ChooseMode();
        
        void initGraphics();
        void update(int8_t *state);
        
    private:
        int8_t m_mode;
        
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
