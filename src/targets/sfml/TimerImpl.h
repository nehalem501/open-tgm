/* TimerImpl.h - SFML */

#ifndef TIMER_SFML_H
#define TIMER_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <core/Timer.h>

class TimerImpl : public Core::Timer, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        void updateSize(Stack *stack);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::VertexArray m_timer_vert;
};

#endif
