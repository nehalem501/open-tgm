/* digits.h */

#ifndef DIGITS_H
#define DIGITS_H

#include <stdint.h>

#ifdef TARGET_SFML
#include <string>
#include <vector>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#endif


#ifdef TARGET_SFML
class Digits : public sf::Drawable {
#else
class Digits {
#endif
    public:
        Digits();
    
        void init(int8_t pos_x, int8_t pos_y);
        void initGraphics();
        
        void update(uint32_t number);
        void updateGraphics();
    
    private:
        uint32_t m_value;
        int8_t m_pos_x, m_pos_y;
        bool m_has_changed;

    #ifdef TARGET_SFML
    public:
        sf::VertexArray m_vertices;
 
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};
#endif
