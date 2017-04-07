/* frame.h */

#ifndef FRAME_H
#define FRAME_H

#include "player.h"
#include "stack.h"


#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Frame : public sf::Drawable {
#else
class Frame {
#endif
    public:
        void init(Stack *stack);
        void initGraphics();
        void updateGraphics();
        
    private:
        Stack *m_stack;
        //color;
        
    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(sf::Vector2u screenSize);
    private:
        sf::RectangleShape m_background;
        sf::VertexArray m_frame;
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
