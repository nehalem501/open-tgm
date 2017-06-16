/* TimerImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
#include "TimerImpl.h"

void TimerImpl::initGraphics() {
    m_timer_vert.setPrimitiveType(sf::Quads);
    m_timer_vert.resize(8 * 4);

    for (unsigned int i = 0; i < m_timer_vert.getVertexCount(); i++) {
        m_timer_vert[i].color = sf::Color(255, 255, 255, 255);
    }
}

void TimerImpl::updateGraphics() {
    for (unsigned i = 0; i < 8; i++) {
        int tile;

        if (i == 2 || i == 5) {
            tile = 10;
        } else if (i > 2 && i < 5) {
            tile = str[i-1];
        } else if (i > 5) {
            tile = str[i-2];
        } else {
            tile = str[i];
        }

        int tu = tile % (timer_tex.getSize().x / 90);
        int tv = tile / (timer_tex.getSize().x / 90);

        sf::Vertex* quad = &m_timer_vert[i * 4];

        quad[0].texCoords = sf::Vector2f(tu * 102.0f, tv * 160.0f);
        quad[1].texCoords = sf::Vector2f((tu + 1) * 102.0f, tv * 160.0f);
        quad[2].texCoords = sf::Vector2f((tu + 1) * 102.0f, (tv + 1) * 160.0f);
        quad[3].texCoords = sf::Vector2f(tu * 102.0f, (tv + 1) * 160.0f);
    }
}

void TimerImpl::updateSize(Stack *stack) {
    int pos_x = stack->m_pos_x + tile_size * 12;
    int pos_y = stack->m_pos_y + tile_size * 21;

    int offset = 0;
    float factor = 91.0f;

    for (unsigned int i = 0; i < 8; ++i) {
        sf::Vertex* quad = &m_timer_vert[i * 4];

        if (i == 2 || i == 5) {
            // Separator
            int p_x = pos_x + offset - (26.0f * tile_size / factor);
            quad[0].position = sf::Vector2f(p_x, pos_y);
            quad[1].position = sf::Vector2f(p_x + (int) (102.0f * tile_size / factor), pos_y);
            quad[2].position = sf::Vector2f(p_x + (int) (102.0f * tile_size / factor), pos_y + (int) (160.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(p_x, pos_y + (int) (160.0f * tile_size / factor));

            offset += 30.0f * tile_size / factor;
        } else {
            // Digits
            quad[0].position = sf::Vector2f(pos_x + offset, pos_y);
            quad[1].position = sf::Vector2f(pos_x + offset + (int) (102.0f * tile_size / factor), pos_y);
            quad[2].position = sf::Vector2f(pos_x + offset + (int) (102.0f * tile_size / factor), pos_y + (int) (160.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(pos_x + offset, pos_y + (int) (160.0f * tile_size / factor));

            offset += 80.0f * tile_size / factor;
        }
    }
}

void TimerImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_timer_vert, &timer_tex);
}
