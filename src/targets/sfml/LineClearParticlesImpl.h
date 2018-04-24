/* LineClearParticlesImpl.h - SFML */

#ifndef LINE_CLEAR_PARTICLES_SFML_H
#define LINE_CLEAR_PARTICLES_SFML_H

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <core/LineClearParticles.h>

#define COLOR_SEED_SIZE 11
#define PARTICLES_NUMBER 880

struct Particle {
    sf::Vector2f velocity;
    int lifetime;
};

class LineClearParticlesImpl : public Core::LineClearParticles,
                               public sf::Drawable,
                               public sf::Transformable {
    public:
        void init();
        void update();
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    private:
        void resetParticle(std::size_t index);

        int m_lifetime, m_first;
        int m_color_seed[COLOR_SEED_SIZE];
        //sf::Vector2f m_emitter;
        std::vector<Particle> m_particles;
        sf::VertexArray m_vertices;
};

#endif
