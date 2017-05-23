/* DigitsImpl.cpp - SFML */

#include <stdint.h>
#include <Stack.h>
#include "GlobalSFML.h"
#include "DigitsImpl.h"

void DigitsImpl::initGraphics() {
    m_vertices.setPrimitiveType(sf::Quads);
}

void DigitsImpl::updateGraphics(Stack *stack) {
    if (m_has_changed) {
        m_has_changed = false;
        updateVertices(stack);
    }
}

void DigitsImpl::updateSize(Stack *stack) {
    updateVertices(stack);
}

void DigitsImpl::updateVertices(Stack *stack) {
    int game_pos_x = stack->m_pos_x;
    int game_pos_y = stack->m_pos_y;

    int offset = 0;
    int position_x = game_pos_x + tile_size * m_pos_x;
    int position_y = game_pos_y + tile_size * m_pos_y + tile_size / 6;
    float factor = 131.0f;

    uint32_t tmp = m_value;

    std::vector<uint32_t> digits;
    if (m_value > 0) {
        while (tmp > 0) {
            digits.push_back(tmp % 10);
            tmp /= 10;
        }
    } else {
        digits.push_back(0);
    }

    m_vertices.resize(4 * digits.size());

    for (int i = 0; i < (int) digits.size(); ++i) {
        sf::Vertex* quad = &m_vertices[(std::size_t) i * 4];
        int n = digits.at(digits.size() - i - 1);

        switch(n) {
            case 0:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(0.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(136.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(136.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(0.0f, 168.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 1:
            quad[0].position = sf::Vector2f(position_x + offset + (int) (0.0f * tile_size / factor), position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (104.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (104.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset + (int) (0.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(136.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(240.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(240.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(136.0F, 168.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 2:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(240.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(376.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(376.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(240.0f, 168.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 3:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(376.0f, 0.0f);
            quad[1].texCoords = sf::Vector2f(512.0f, 0.0f);
            quad[2].texCoords = sf::Vector2f(512.0f, 168.0f);
            quad[3].texCoords = sf::Vector2f(376.0f, 168.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 4:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(0.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(136.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(136.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(0.0f, 336.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 5:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(136.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(272.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(272.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(136.0f, 336.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 6:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(272.0f, 168.0f);
            quad[1].texCoords = sf::Vector2f(408.0f, 168.0f);
            quad[2].texCoords = sf::Vector2f(408.0f, 336.0f);
            quad[3].texCoords = sf::Vector2f(272.0f, 336.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 7:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(0.0f, 336.0f);
            quad[1].texCoords = sf::Vector2f(136.0f, 336.0f);
            quad[2].texCoords = sf::Vector2f(136.0f, 504.0f);
            quad[3].texCoords = sf::Vector2f(0.0f, 504.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 8:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(136.0f, 336.0f);
            quad[1].texCoords = sf::Vector2f(272.0f, 336.0f);
            quad[2].texCoords = sf::Vector2f(272.0f, 504.0f);
            quad[3].texCoords = sf::Vector2f(136.0f, 504.0f);
            offset += 136.0f * tile_size / factor;
            break;

            case 9:
            quad[0].position = sf::Vector2f(position_x + offset, position_y);
            quad[1].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y);
            quad[2].position = sf::Vector2f(position_x + offset + (int) (136.0f * tile_size / factor), position_y + (int) (168.0f * tile_size / factor));
            quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (168.0f * tile_size / factor));

            quad[0].texCoords = sf::Vector2f(272.0f, 336.0f);
            quad[1].texCoords = sf::Vector2f(408.0f, 336.0f);
            quad[2].texCoords = sf::Vector2f(408.0f, 504.0f);
            quad[3].texCoords = sf::Vector2f(272.0f, 504.0f);
            offset += 136.0f * tile_size / factor;
            break;
        }

        quad[0].color = sf::Color(255, 255, 255, 255);
        quad[1].color = sf::Color(255, 255, 255, 255);
        quad[2].color = sf::Color(255, 255, 255, 255);
        quad[3].color = sf::Color(255, 255, 255, 255);
    }
}

void DigitsImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_vertices, &digits_tex);
}
