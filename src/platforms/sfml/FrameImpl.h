/* FrameImpl.h - SFML */

#ifndef FRAME_SFML_H
#define FRAME_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <core/Frame.h>

class FrameImpl : public Core::Frame, public sf::Drawable {
    public:
        void init_graphics();
        void update_graphics();
        void resize(Stack *stack);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::RectangleShape m_background;
        sf::VertexArray m_frame;
};

#endif
