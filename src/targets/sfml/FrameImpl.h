/* FrameImpl.h - SFML */

#ifndef FRAME_SFML_H
#define FRAME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <core/Frame.h>

class FrameImpl : public Core::Frame, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        void updateSize(Stack *stack);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::RectangleShape m_background;
        sf::VertexArray m_frame;
};

#endif
