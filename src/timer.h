/* timer.h */

#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#endif


#ifdef TARGET_SFML
class Timer : public sf::Drawable {
#else
class Timer {
#endif
    public:
        uint32_t m_frames;
        float m_time;
    
        int8_t m_pos_x, m_pos_y;
        int8_t str[6];

        void init();
        void initGraphics();

        void start();

        void updateTime();
        void updateGraphics();

    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        sf::VertexArray m_timer_vert;
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};
#endif
