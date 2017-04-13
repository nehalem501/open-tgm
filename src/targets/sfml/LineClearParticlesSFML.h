/* LineClearParticlesSFML.h */

#ifndef LINE_CLEAR_PARTICLES_H
#define LINE_CLEAR_PARTICLES_H

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#define PARTICLES_NUMBER 880

struct Particle {
    sf::Vector2f velocity;
    int lifetime;
};
#endif


#ifdef TARGET_SFML
class LineClearParticle : public sf::Drawable, public sf::Transformable {
#else
class LineClearParticle {
#endif
    public:
        LineClearParticle();
        void setEmitter(float position_x, float position_y);
        void updateSize(float gamePosX, float gamePosY, float displayTileSize);
        void update();
        void init();
        bool end();

    private:


    #ifdef TARGET_SFML
    public:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    private:
        void resetParticle(std::size_t index);

        float displaySize, posX, posY;
        int m_lifetime;
        int m_first;
        int colorSeed[11];
        sf::Vector2f m_emitter;
        std::vector<Particle> m_particles;
        sf::VertexArray m_vertices;
    #endif
    #ifdef TARGET_DUMMY
    public:
        void draw();
    private:
    #endif
};
#endif
