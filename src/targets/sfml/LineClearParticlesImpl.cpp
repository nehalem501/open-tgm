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
    m_lifetime = 34;
    m_first = 0;

    // Allocate vertices
    m_particles.reserve(PARTICLES_NUMBER);
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(PARTICLES_NUMBER * 4);

    // color seed
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
        int color_value;
        sf::Vector2f position;
        if (i >= PARTICLES_NUMBER / 2) {
            color_value = floor((i - (PARTICLES_NUMBER / 2.0f)) / 80.0f);
            position.x = pos_x + floor((i - (PARTICLES_NUMBER / 2.0f)) /
                                       40.0f) * tile_size;
            position.y = pos_y + tile_size;
        } else {
            color_value = floor(i / 80.0f);
            position.x = pos_x + floor(i / 40.0f) * tile_size;
            position.y = pos_y;
        }

        switch (rand() % 4) {
            case 0:
            case 1:
            case 2:
                quad[0].position = position;
                quad[1].position = position + sf::Vector2f(tile_size / 2.5f, 0.0f);
                quad[2].position = position + sf::Vector2f(tile_size / 2.5f, tile_size / 2.5f);
                quad[3].position = position + sf::Vector2f(0.0f, tile_size / 2.5f);
                break;

            case 3:
                quad[0].position = position;
                quad[1].position = position + sf::Vector2f(tile_size / 3.0f, 0.0f);
                quad[2].position = position + sf::Vector2f(tile_size / 3.0f, tile_size / 3.0f);
                quad[3].position = position + sf::Vector2f(0.0f, tile_size / 3.0f);
                break;
        }

        quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
        quad[1].texCoords = sf::Vector2f(64.0f, 0.0f);
        quad[2].texCoords = sf::Vector2f(64.0f, 64.0f);
        quad[3].texCoords = sf::Vector2f(0.0f, 64.0f);

        sf::Color color;
        switch (m_color_seed[color_value]) {
            case 0:
                color = sf::Color(255, 128, 128, 255);
                break;

            case 1:
                color = sf::Color(128, 255, 128, 255);
                break;

            case 2:
                color = sf::Color(128, 128, 255, 255);
                break;

            case 3:
                color = sf::Color(255, 255, 128, 255);
                break;

            case 4:
                color = sf::Color(128, 255, 255, 255);
                break;

            case 5:
                color = sf::Color(255, 128, 255, 255);
                break;
        }

        quad[0].color = color;
        quad[1].color = color;
        quad[2].color = color;
        quad[3].color = color;
    }

    update();
    m_first = 0;
}

void LineClearParticlesImpl::update() {
    m_first++;

    // No need to update vertices when outside screen
    if (m_first > 100)
        return;

    for (unsigned int i = 0; i < PARTICLES_NUMBER; i++) {
        // update the particle lifetime
        sf::Vertex* quad = &m_vertices[i * 4];
        Particle& p = m_particles[i];

        if (m_first > 28.0f)
            p.lifetime-= 2;
        else
            p.lifetime-= 1;

        // Stop displaying dead particles
        if (p.lifetime <= 0) {
            quad[0].color.a = 0;
            quad[1].color.a = 0;
            quad[2].color.a = 0;
            quad[3].color.a = 0;

            continue;
        }

        // update the position of the corresponding vertex
        p.velocity.x *= 0.95f;
        p.velocity.y = (p.velocity.y * 0.95f) + 0.20f;

        quad[0].position.x += p.velocity.x;
        quad[0].position.y += p.velocity.y;

        quad[1].position.x += p.velocity.x;
        quad[1].position.y += p.velocity.y;

        quad[2].position.x += p.velocity.x;
        quad[2].position.y += p.velocity.y;

        quad[3].position.x += p.velocity.x;
        quad[3].position.y += p.velocity.y;

        // update the alpha (transparency) of the particle according to its lifetime
        float ratio = (float) p.lifetime / (float) m_lifetime;

        quad[0].color.a = static_cast<sf::Uint8>(ratio * 255);
        quad[1].color.a = static_cast<sf::Uint8>(ratio * 255);
        quad[2].color.a = static_cast<sf::Uint8>(ratio * 255);
        quad[3].color.a = static_cast<sf::Uint8>(ratio * 255);
    }
}

void LineClearParticlesImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (m_first > 1) {
        states.texture = &particle_tex;
        states.blendMode = sf::BlendAdd;
        target.draw(m_vertices, states);
    }
}
