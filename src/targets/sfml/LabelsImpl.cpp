/* LabelsImpl.cpp - SFML */

#include <cmath>
#include <cstdio>
#include <string>
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include "GlobalSFML.h"
#include "LabelsImpl.h"

using namespace std;

void LabelsImpl::init_graphics(Stack *stack) {
    length = 0;

    str.clear();
    positions.clear();
    m_vertices.clear();

    for (unsigned int i = 0; i < m_mode->labels_nb(); i++) {
        str.push_back(string(m_mode->get_label(i).string));
        positions.push_back(sf::Vector2f(m_mode->get_label(i).x,
                                         m_mode->get_label(i).y));
    }

    labels_tex.setSmooth(true);

    for (unsigned int i = 0; i < str.size(); i++) {
        length += str[i].size();
    }

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize((std::size_t)length * 4);

    for (unsigned int i = 0; i < length; ++i) {
        sf::Vertex* quad = &m_vertices[i * 4];

        quad[0].color = sf::Color(0, 0, 0, 0);
        quad[1].color = sf::Color(0, 0, 0, 0);
        quad[2].color = sf::Color(0, 0, 0, 0);
        quad[3].color = sf::Color(0, 0, 0, 0);
    }

    resize(stack);
}

void LabelsImpl::resize(Stack *stack) {
    int pos_x = stack->m_pos_x - tile_size / 2;
    int pos_y = stack->m_pos_y;

    int offset;
    int position_x;
    int position_y;
    int char_position = 0;
    float factor = 65.0f;

    for (unsigned int i = 0; i < str.size(); ++i) {
        position_x = pos_x + tile_size * positions[i].x;
        position_y = pos_y + tile_size * positions[i].y;
        //position_x = 200;
        //position_y = 200;
        offset = 0;

        for (unsigned int j = 0; j < str.at(i).size(); ++j) {
            char c = str.at(i).at(j);
            sf::Vertex* quad = &m_vertices[((length - 1) - char_position) * 4];
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
                    quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                    quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                    quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                    quad[0].texCoords = sf::Vector2f(65.0f, 15.0f);
                    quad[1].texCoords = sf::Vector2f(128.0f, 15.0f);
                    quad[2].texCoords = sf::Vector2f(128.0f, 79.0f);
                    quad[3].texCoords = sf::Vector2f(65.0f, 79.0f);
                    offset += 62.0f * tile_size / factor;
                    break;

                case 'B':
                    quad[0].position = sf::Vector2f(position_x + offset, position_y);
                    quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                    quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                    quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                    quad[0].texCoords = sf::Vector2f(157.0f, 15.0f);
                    quad[1].texCoords = sf::Vector2f(220.0f, 15.0f);
                    quad[2].texCoords = sf::Vector2f(220.0f, 79.0f);
                    quad[3].texCoords = sf::Vector2f(157.0F, 79.0f);
                    offset += 62.0f * tile_size / factor;
                    break;

                case 'C':
                    quad[0].position = sf::Vector2f(position_x + offset, position_y);
                    quad[1].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y);
                    quad[2].position = sf::Vector2f(position_x + offset + (int) (63.0f * tile_size / factor), position_y + (int) (64.0f * tile_size / factor));
                    quad[3].position = sf::Vector2f(position_x + offset, position_y + (int) (64.0f * tile_size / factor));

                    quad[0].texCoords = sf::Vector2f(249.0f, 15.0f);
                    quad[1].texCoords = sf::Vector2f(312.0f, 15.0f);
                    quad[2].texCoords = sf::Vector2f(312.0f, 79.0f);
                    quad[3].texCoords = sf::Vector2f(249.0f, 79.0f);
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

}

void LabelsImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_vertices, &labels_tex);
}
