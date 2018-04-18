/* TimerImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
#include "TimerImpl.h"

void TimerImpl::init_graphics() {
    m_timer_vert.setPrimitiveType(sf::Quads);
    m_timer_vert.resize(8 * 4);

    for (unsigned int i = 0; i < m_timer_vert.getVertexCount(); i++) {
        m_timer_vert[i].color = sf::Color(255, 255, 255, 255);
    }
}

void TimerImpl::update_graphics() {
    for (unsigned i = 0; i < 8; i++) {
        int tile;

        if (i == 2 || i == 5) {
            tile = 10;
        } else if (i > 2 && i < 5) {
            tile = m_str[i-1];
        } else if (i > 5) {
            tile = m_str[i-2];
        } else {
            tile = m_str[i];
        }

        sf::Vertex* quad = &m_timer_vert[i * 4];

        switch(tile) {
            case 0:
            quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(136.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(136.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(0.0f, 168.0f);
            break;

            case 1:
            quad[0].texCoords = sf::Vector2f(136.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(240.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(240.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(136.0F, 168.0f);
            break;

            case 2:
            quad[0].texCoords = sf::Vector2f(240.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(376.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(376.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(240.0f, 168.0f);
            break;

            case 3:
            quad[0].texCoords = sf::Vector2f(376.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(512.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(512.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(376.0f, 168.0f);
            break;

            case 4:
            quad[0].texCoords = sf::Vector2f(0.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(136.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(136.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(0.0f, 336.0f);
            break;

            case 5:
            quad[0].texCoords = sf::Vector2f(136.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(272.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(272.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(136.0f, 336.0f);
            break;

            case 6:
            quad[0].texCoords = sf::Vector2f(272.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(408.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(408.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(272.0f, 336.0f);
            break;

            case 7:
            quad[0].texCoords = sf::Vector2f(0.0f, 336.0f);
            quad[1].texCoords = sf::Vector2f(136.0f, 336.0f);
            quad[2].texCoords = sf::Vector2f(136.0f, 504.0f);
            quad[3].texCoords = sf::Vector2f(0.0f, 504.0f);
            break;

            case 8:
            quad[0].texCoords = sf::Vector2f(136.0f, 336.0f);
            quad[1].texCoords = sf::Vector2f(272.0f, 336.0f);
            quad[2].texCoords = sf::Vector2f(272.0f, 504.0f);
            quad[3].texCoords = sf::Vector2f(136.0f, 504.0f);
            break;

            case 9:
            quad[0].texCoords = sf::Vector2f(272.0f, 336.0f);
            quad[1].texCoords = sf::Vector2f(408.0f, 336.0f);
            quad[2].texCoords = sf::Vector2f(408.0f, 504.0f);
            quad[3].texCoords = sf::Vector2f(272.0f, 504.0f);
            break;

            case 10:
            quad[0].texCoords = sf::Vector2f(409.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(480.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(480.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(409.0f, 336.0f);
            break;
        }
    }
}

void TimerImpl::resize(Stack *stack) {
    int pos_x = stack->m_pos_x + tile_size * 12 - tile_size / 2;
    int pos_y = stack->m_pos_y + tile_size * 21 + tile_size / 4;

    int offset = 0;
    float factor = 131.0f;

    for (unsigned int i = 0; i < 8; ++i) {
        sf::Vertex* quad = &m_timer_vert[i * 4];

        if (i == 2 || i == 5) {
            // Separator
            quad[0].position = sf::Vector2f(pos_x + offset, pos_y);
            quad[1].position = sf::Vector2f(pos_x + offset + (int) (72.0f * tile_size / factor), pos_y);
            quad[2].position = sf::Vector2f(pos_x + offset + (int) (72.0f * tile_size / factor), pos_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(pos_x + offset, pos_y + (int) (168.0f * tile_size / factor));

            offset += 72.0f * tile_size / factor;
        } else {
            // Digits
            quad[0].position = sf::Vector2f(pos_x + offset, pos_y);
            quad[1].position = sf::Vector2f(pos_x + offset + (int) (136.0f * tile_size / factor), pos_y);
            quad[2].position = sf::Vector2f(pos_x + offset + (int) (136.0f * tile_size / factor), pos_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(pos_x + offset, pos_y + (int) (168.0f * tile_size / factor));

            offset += 136.0f * tile_size / factor;
        }
    }
}

void TimerImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_timer_vert, &digits_tex);
}
