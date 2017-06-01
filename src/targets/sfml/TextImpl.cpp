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
    int position_x = tile_size * m_pos_x;
    int position_y = tile_size * m_pos_y;

    //int position_x = 200;
    //int position_y = 200;
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

            case '?':
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

            case '!':
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

            case '.':
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

            case ',':
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

            case ':':
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

            case '0':
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

            case '1':
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

            case '2':
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

            case '3':
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

            case '4':
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

            case '5':
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

            case '6':
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

            case '7':
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

            case '8':
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

            case '9':
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
                quad[1].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(76.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(149.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(149.0f, 243.0f);
                quad[3].texCoords = sf::Vector2f(76.0f, 243.0f);
                offset += 68.0f * tile_size / factor;
                break;

            case 'D':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(150.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(224.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(224.0f, 243.0f);
                quad[3].texCoords = sf::Vector2f(150.0f, 243.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'E':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (71.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (71.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(225.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(296.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(296.0f, 243.0f);
                quad[3].texCoords = sf::Vector2f(225.0f, 243.0f);
                offset += 66.0f * tile_size / factor;
                break;

            case 'F':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (68.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (68.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(297.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(365.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(365.0f, 243.0f);
                quad[3].texCoords = sf::Vector2f(297.0f, 243.0f);
                offset += 63.0f * tile_size / factor;
                break;

            case 'G':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(366.0f, 162.0f);
                quad[1].texCoords = sf::Vector2f(441.0f, 162.0f);
                quad[2].texCoords = sf::Vector2f(441.0f, 243.0f);
                quad[3].texCoords = sf::Vector2f(366.0f, 243.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'H':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(0.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(75.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(75.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(0.0f, 324.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'I':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (31.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (31.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(76.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(107.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(107.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(76.0f, 324.0f);
                offset += 26.0f * tile_size / factor;
                break;

            case 'J':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(109.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(182.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(182.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(109.0f, 324.0f);
                offset += 68.0f * tile_size / factor;
                break;

            case 'K':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(183.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(256.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(256.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(183.0f, 324.0f);
                offset += 68.0f * tile_size / factor;
                break;

            case 'L':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(258.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(332.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(332.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(258.0f, 324.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'M':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (99.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (99.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(333.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(432.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(432.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(333.0f, 324.0f);
                offset += 94.0f * tile_size / factor;
                break;

            case 'N':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(434.0f, 243.0f);
                quad[1].texCoords = sf::Vector2f(508.0f, 243.0f);
                quad[2].texCoords = sf::Vector2f(508.0f, 324.0f);
                quad[3].texCoords = sf::Vector2f(434.0f, 324.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'O':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(0.0f, 325.0f);
                quad[1].texCoords = sf::Vector2f(75.0f, 325.0f);
                quad[2].texCoords = sf::Vector2f(75.0f, 406.0f);
                quad[3].texCoords = sf::Vector2f(0.0f, 406.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'P':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(76.0f, 325.0f);
                quad[1].texCoords = sf::Vector2f(150.0f, 325.0f);
                quad[2].texCoords = sf::Vector2f(150.0f, 406.0f);
                quad[3].texCoords = sf::Vector2f(76.0f, 406.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'Q':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (85.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (85.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(151.0f, 325.0f);
                quad[1].texCoords = sf::Vector2f(225.0f, 325.0f);
                quad[2].texCoords = sf::Vector2f(225.0f, 410.0f);
                quad[3].texCoords = sf::Vector2f(151.0f, 410.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'R':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(226.0f, 325.0f);
                quad[1].texCoords = sf::Vector2f(300.0f, 325.0f);
                quad[2].texCoords = sf::Vector2f(300.0f, 406.0f);
                quad[3].texCoords = sf::Vector2f(226.0f, 406.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'S':
                quad[0].position = sf::Vector2f(position_x + offset + (int) (-3.0f * tile_size / factor), position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset + (int) (-3.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(301.0f, 325.0f);
                quad[1].texCoords = sf::Vector2f(375.0f, 325.0f);
                quad[2].texCoords = sf::Vector2f(375.0f, 406.0f);
                quad[3].texCoords = sf::Vector2f(301.0f, 406.0f);
                offset += 67.0f * tile_size / factor;
                break;

            case 'T':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(376.0f, 325.0f);
                quad[1].texCoords = sf::Vector2f(450.0f, 325.0f);
                quad[2].texCoords = sf::Vector2f(450.0f, 406.0f);
                quad[3].texCoords = sf::Vector2f(376.0f, 406.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'U':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(0.0f, 411.0f);
                quad[1].texCoords = sf::Vector2f(75.0f, 411.0f);
                quad[2].texCoords = sf::Vector2f(75.0f, 492.0f);
                quad[3].texCoords = sf::Vector2f(0.0f, 492.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'V':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (74.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(76.0f, 411.0f);
                quad[1].texCoords = sf::Vector2f(150.0f, 411.0f);
                quad[2].texCoords = sf::Vector2f(150.0f, 492.0f);
                quad[3].texCoords = sf::Vector2f(76.0f, 492.0f);
                offset += 69.0f * tile_size / factor;
                break;

            case 'W':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (107.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (107.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(151.0f, 411.0f);
                quad[1].texCoords = sf::Vector2f(258.0f, 411.0f);
                quad[2].texCoords = sf::Vector2f(258.0f, 492.0f);
                quad[3].texCoords = sf::Vector2f(151.0f, 492.0f);
                offset += 102.0f * tile_size / factor;
                break;

            case 'X':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(259.0f, 411.0f);
                quad[1].texCoords = sf::Vector2f(334.0f, 411.0f);
                quad[2].texCoords = sf::Vector2f(334.0f, 492.0f);
                quad[3].texCoords = sf::Vector2f(259.0f, 492.0f);
                offset += 70.0f * tile_size / factor;
                break;

            case 'Y':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (73.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(336.0f, 411.0f);
                quad[1].texCoords = sf::Vector2f(409.0f, 411.0f);
                quad[2].texCoords = sf::Vector2f(409.0f, 492.0f);
                quad[3].texCoords = sf::Vector2f(336.0f, 492.0f);
                offset += 68.0f * tile_size / factor;
                break;

            case 'Z':
                quad[0].position = sf::Vector2f(position_x + offset, position_y);
                quad[1].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y);
                quad[2].position = sf::Vector2f(position_x + offset + (int) (75.0f * tile_size / factor), position_y + (int) (81.0f * tile_size / factor));
                quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (81.0f * tile_size / factor));

                quad[0].texCoords = sf::Vector2f(410.0f, 411.0f);
                quad[1].texCoords = sf::Vector2f(485.0f, 411.0f);
                quad[2].texCoords = sf::Vector2f(485.0f, 492.0f);
                quad[3].texCoords = sf::Vector2f(410.0f, 492.0f);
                offset += 70.0f * tile_size / factor;
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
