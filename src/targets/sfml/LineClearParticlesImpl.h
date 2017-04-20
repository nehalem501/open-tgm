/* LineClearParticlesImpl.h */

#ifndef LINE_CLEAR_PARTICLES_SFML_H
#define LINE_CLEAR_PARTICLES_SFML_H

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <common/BaseLineClearParticles.h>

#define PARTICLES_NUMBER 880

struct Particle {
    sf::Vector2f velocity;
    int lifetime;
};

class LineClearParticlesImpl : public BaseLineClearParticles, public sf::Drawable, public sf::Transformable {
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
};

#endif
