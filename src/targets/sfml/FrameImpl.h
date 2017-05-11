/* FrameImpl.h - SFML */

#ifndef FRAME_SFML_H
#define FRAME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <common/BaseFrame.h>

class FrameImpl : public BaseFrame, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void updateSize(Stack *stack, sf::Vector2u screenSize);

    private:
        sf::RectangleShape m_background;
        sf::VertexArray m_frame;
};

#endif
