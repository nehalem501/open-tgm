/* TextImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include "GlobalSFML.h"
#include "TextImpl.h"

void TextImpl::initGraphics() {
    m_vertices.setPrimitiveType(sf::Quads);
}

void TextImpl::updateGraphics() {
    if (m_has_changed) {
        m_vertices.resize(m_length * 4);
        updateVertices();
    }
}

void TextImpl::updateSize() {
    updateVertices();
}

void TextImpl::updateVertices() {
    int offset = 0;

    m_has_changed = false;
    //int position_x = game_pos_x + tile_size * m_pos_x;
    //int position_y = game_pos_y + tile_size * m_pos_y + tile_size / 6;

    int position_x = 200;
    int position_y = 200;
    int char_position = 0;

    float factor = 30.0f;

    for (unsigned int i = 0; i < m_length; ++i) {
        char c = m_str[i];
        //std::size_t truc = ((m_length - 1) - char_position) * 4;
        std::size_t truc = i * 4;
        sf::Vertex* quad = &m_vertices[(std::size_t) truc];
        //sf::Vertex* quad = &m_vertices[char_position * 4];
        char_position++;

        switch(c) {
            case ' ':
                offset += 30.0f * tile_size / factor;
                break;

            case '\'':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (22.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (22.0f * tile_size / factor), position_y + (int) (33.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (33.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(14.0f, 15.0f);
                quad[1].texCoords = sf::Vector2f(36.0f, 15.0f);
                quad[2].texCoords = sf::Vector2f(36.0f, 48.0f);
                quad[3].texCoords = sf::Vector2f(14.0f, 48.0f);
                offset += 21.0f * tile_size / factor;
                break;

            case 'A':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(408.0f, 81.0f);
                quad[1].texCoords = sf::Vector2f(483.0f, 81.0f);
                quad[2].texCoords = sf::Vector2f(483.0f, 162.0f);
                quad[3].texCoords = sf::Vector2f(408.0f, 162.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'B':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(0.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(75.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(75.0f, 243.0f);
                quad[3].texCoords = sf::Vector2f(0.0F, 243.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'C':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(0.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(312.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(312.0f, 79.0f);
                quad[3].texCoords = sf::Vector2f(0.0f, 79.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'D':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(341.0f, 15.0f);
                quad[1].texCoords = sf::Vector2f(404.0f, 15.0f);
                quad[2].texCoords = sf::Vector2f(404.0f, 79.0f);
                quad[3].texCoords = sf::Vector2f(341.0f, 79.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'E':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(433.0f, 15.0f);
                quad[1].texCoords = sf::Vector2f(496.0f, 15.0f);
                quad[2].texCoords = sf::Vector2f(496.0f, 79.0f);
                quad[3].texCoords = sf::Vector2f(433.0f, 79.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'F':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(14.0f, 108.0f);
                quad[1].texCoords = sf::Vector2f(77.0f, 108.0f);
                quad[2].texCoords = sf::Vector2f(77.0f, 172.0f);
                quad[3].texCoords = sf::Vector2f(14.0f, 172.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'G':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(106.0f, 108.0f);
                quad[1].texCoords = sf::Vector2f(169.0f, 108.0f);
                quad[2].texCoords = sf::Vector2f(169.0f, 172.0f);
                quad[3].texCoords = sf::Vector2f(106.0f, 172.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'H':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(198.0f, 108.0f);
                quad[1].texCoords = sf::Vector2f(261.0f, 108.0f);
                quad[2].texCoords = sf::Vector2f(261.0f, 172.0f);
                quad[3].texCoords = sf::Vector2f(198.0f, 172.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'I':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (22.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (22.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(290.0f, 108.0f);
                quad[1].texCoords = sf::Vector2f(312.0f, 108.0f);
                quad[2].texCoords = sf::Vector2f(312.0f, 172.0f);
                quad[3].texCoords = sf::Vector2f(290.0f, 172.0f);
                offset += 21.0f * tile_size / factor;
                break;

            case 'J':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(341.0f, 108.0f);
                quad[1].texCoords = sf::Vector2f(404.0f, 108.0f);
                quad[2].texCoords = sf::Vector2f(404.0f, 172.0f);
                quad[3].texCoords = sf::Vector2f(341.0f, 172.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'K':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (56.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (56.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(433.0f, 108.0f);
                quad[1].texCoords = sf::Vector2f(489.0f, 108.0f);
                quad[2].texCoords = sf::Vector2f(489.0f, 172.0f);
                quad[3].texCoords = sf::Vector2f(433.0f, 172.0f);
                offset += 55.0f * tile_size / factor;
                break;

            case 'L':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(14.0f, 201.0f);
                quad[1].texCoords = sf::Vector2f(77.0f, 201.0f);
                quad[2].texCoords = sf::Vector2f(77.0f, 265.0f);
                quad[3].texCoords = sf::Vector2f(14.0f, 265.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'M':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(106.0f, 201.0f);
                quad[1].texCoords = sf::Vector2f(169.0f, 201.0f);
                quad[2].texCoords = sf::Vector2f(169.0f, 265.0f);
                quad[3].texCoords = sf::Vector2f(106.0f, 265.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'N':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(198.0f, 201.0f);
                quad[1].texCoords = sf::Vector2f(261.0f, 201.0f);
                quad[2].texCoords = sf::Vector2f(261.0f, 265.0f);
                quad[3].texCoords = sf::Vector2f(198.0f, 265.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'O':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(290.0f, 201.0f);
                quad[1].texCoords = sf::Vector2f(353.0f, 201.0f);
                quad[2].texCoords = sf::Vector2f(353.0f, 265.0f);
                quad[3].texCoords = sf::Vector2f(290.0f, 265.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'P':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(382.0f, 201.0f);
                quad[1].texCoords = sf::Vector2f(445.0f, 201.0f);
                quad[2].texCoords = sf::Vector2f(445.0f, 265.0f);
                quad[3].texCoords = sf::Vector2f(382.0f, 265.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'Q':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (75.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (75.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(14.0f, 294.0f);
                quad[1].texCoords = sf::Vector2f(77.0f, 294.0f);
                quad[2].texCoords = sf::Vector2f(77.0f, 369.0f);
                quad[3].texCoords = sf::Vector2f(14.0f, 369.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'R':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(106.0f, 294.0f);
                quad[1].texCoords = sf::Vector2f(169.0f, 294.0f);
                quad[2].texCoords = sf::Vector2f(169.0f, 358.0f);
                quad[3].texCoords = sf::Vector2f(106.0f, 358.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'S':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(198.0f, 294.0f);
                quad[1].texCoords = sf::Vector2f(261.0f, 294.0f);
                quad[2].texCoords = sf::Vector2f(261.0f, 358.0f);
                quad[3].texCoords = sf::Vector2f(198.0f, 358.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'T':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(290.0f, 294.0f);
                quad[1].texCoords = sf::Vector2f(353.0f, 294.0f);
                quad[2].texCoords = sf::Vector2f(353.0f, 358.0f);
                quad[3].texCoords = sf::Vector2f(290.0f, 358.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'U':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(382.0f, 294.0f);
                quad[1].texCoords = sf::Vector2f(445.0f, 294.0f);
                quad[2].texCoords = sf::Vector2f(445.0f, 358.0f);
                quad[3].texCoords = sf::Vector2f(382.0f, 358.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'V':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(14.0f, 398.0f);
                quad[1].texCoords = sf::Vector2f(77.0f, 398.0f);
                quad[2].texCoords = sf::Vector2f(77.0f, 462.0f);
                quad[3].texCoords = sf::Vector2f(14.0f, 462.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'W':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(106.0f, 398.0f);
                quad[1].texCoords = sf::Vector2f(169.0f, 398.0f);
                quad[2].texCoords = sf::Vector2f(169.0f, 462.0f);
                quad[3].texCoords = sf::Vector2f(106.0f, 462.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'X':
                quad[0].position = sf::Vector2f(position_x + offset - 1, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (62.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (62.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset - 1, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(198.0f, 398.0f);
                quad[1].texCoords = sf::Vector2f(261.0f, 398.0f);
                quad[2].texCoords = sf::Vector2f(261.0f, 462.0f);
                quad[3].texCoords = sf::Vector2f(198.0f, 462.0f);
                offset += 58.0f * tile_size / factor;
                break;

            case 'Y':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(288.0f, 398.0f);
                quad[1].texCoords = sf::Vector2f(351.0f, 398.0f);
                quad[2].texCoords = sf::Vector2f(351.0f, 462.0f);
                quad[3].texCoords = sf::Vector2f(288.0f, 462.0f);
                offset += 62.0f * tile_size / factor;
                break;

            case 'Z':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(380.0f, 398.0f);
                quad[1].texCoords = sf::Vector2f(443.0f, 398.0f);
                quad[2].texCoords = sf::Vector2f(443.0f, 462.0f);
                quad[3].texCoords = sf::Vector2f(380.0f, 462.0f);
                offset += 62.0f * tile_size / factor;
                break;
        }

        quad[0].color = sf::Color(255, 255, 255, 255);
        quad[1].color = sf::Color(255, 255, 255, 255);
        quad[2].color = sf::Color(255, 255, 255, 255);
        quad[3].color = sf::Color(255, 255, 255, 255);
    }

}

void TextImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_vertices, &text_tex);
}
