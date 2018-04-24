/* LineClearParticlesImpl.cpp - SFML */

#include <math.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include "GlobalSFML.h"
#include "LineClearParticlesImpl.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void LineClearParticlesImpl::init() {
    for (unsigned int i = 0; i < COLOR_SEED_SIZE; i++) {
        m_color_seed[i] = rand() % 6;
    }

    // Get position in pixel coordinates
    float pos_x = m_stack->m_pos_x + tile_size * - 1;
    float pos_y = m_stack->m_pos_y + tile_size * (m_line - 1);

    for (unsigned int i = 0; i < PARTICLES_NUMBER; i++) {
        // Setup particle parameters
        float angle = (rand() % 360) * M_PI / 180.0f;
        float speed = ((rand() % 50) * tile_size + 1.0f) / 200.0f;
        m_particles[i].velocity = sf::Vector2f(cos(angle) * speed,
                                               sin(angle) * speed);
        m_particles[i].lifetime = (rand() % 20) + 25;

        // Set corresponding vertices' position
        sf::Vertex* quad = &m_vertices[i * 4];
        //if ()
    }
}

void LineClearParticlesImpl::update() {
    //#warning "LineClearParticle::update not unimplemented"
    float pos_x = 0;
    float pos_y = 0;
}

void LineClearParticlesImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    //#warning "SFML LineClearParticle::draw not unimplemented"
}
