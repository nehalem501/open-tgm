/* TimerImpl.h - SFML */

#ifndef TIMER_SFML_H
#define TIMER_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseTimer.h>

class TimerImpl : public BaseTimer, public sf::Drawable {
    public:
        void initGraphics();
        void updateGraphics();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        sf::VertexArray m_timer_vert;
};

#endif
