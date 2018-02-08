/* PlayerImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Shapes.h>
#include <Mode.h>
#include <Stack.h>
#include "GlobalSFML.h"
#include "PlayerImpl.h"

void PlayerImpl::init_graphics() {
    // Init next piece vertices
    m_next_vertices.setPrimitiveType(sf::Quads);
    m_next_vertices.resize((std::size_t) (SIZE * SIZE * 4));

    for (std::size_t i = 0; i < SIZE * SIZE * 4; i++) {
        m_next_vertices[i].color = sf::Color(0, 0, 0, 0);
    }

    // Init player's piece vertices
    m_piece_vertices.setPrimitiveType(sf::Quads);
    m_piece_vertices.resize((std::size_t) (SIZE * SIZE * 4));

    for (std::size_t i = 0; i < SIZE * SIZE * 4; i++) {
        m_piece_vertices[i].color = sf::Color(0, 0, 0, 0);
    }

    // Init ghost piece vertices
    m_ghost_vertices.setPrimitiveType(sf::Quads);
    m_ghost_vertices.resize((std::size_t) (SIZE * SIZE * 4));

    for (std::size_t i = 0; i < SIZE * SIZE * 4; i++) {
        m_ghost_vertices[i].color = sf::Color(0, 0, 0, 0);
    }

    resize();
}

void PlayerImpl::resize() {
    int pos_x = m_stack->m_pos_x;
    int pos_y = m_stack->m_pos_y;

    m_score_display.resize(m_stack);
    m_level_display.resize(m_stack);
    m_section_display.resize(m_stack);

    // Update next piece position
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sf::Vertex* quad = &m_next_vertices[(i + j * SIZE) * 4];

            quad[0].position = sf::Vector2f(pos_x + (i + 3) * tile_size, pos_y + (j - 2) * tile_size);
            quad[1].position = sf::Vector2f(pos_x + (i + 4) * tile_size, pos_y + (j - 2) * tile_size);
            quad[2].position = sf::Vector2f(pos_x + (i + 4) * tile_size, pos_y + (j - 1) * tile_size);
            quad[3].position = sf::Vector2f(pos_x + (i + 3) * tile_size, pos_y + (j - 1) * tile_size);

            quad[0].position.y -= (int) tile_size / 2;
            quad[1].position.y -= (int) tile_size / 2;
            quad[2].position.y -= (int) tile_size / 2;
            quad[3].position.y -= (int) tile_size / 2;
        }
    }

    // Update player's piece position
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sf::Vertex* quad = &m_piece_vertices[(i + j * SIZE) * 4];

            quad[0].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + (m_piece.pos_y - 1 + j) * tile_size);
            quad[1].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + (m_piece.pos_y - 1 + j) * tile_size);
            quad[2].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + ((m_piece.pos_y - 1 + j) + 1) * tile_size);
            quad[3].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + ((m_piece.pos_y - 1 + j) + 1) * tile_size);
        }
    }

    // Update ghost piece position
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            sf::Vertex* quad = &m_ghost_vertices[(i + j * SIZE) * 4];

            quad[0].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + (m_ghost_y - 1 + j) * tile_size);
            quad[1].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + (m_ghost_y - 1 + j) * tile_size);
            quad[2].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + ((m_ghost_y - 1 + j) + 1) * tile_size);
            quad[3].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + ((m_ghost_y - 1 + j) + 1) * tile_size);
        }
    }
}

void PlayerImpl::update_graphics() {
    int pos_x = m_stack->m_pos_x;
    int pos_y = m_stack->m_pos_y;

    //score_display.updateGraphics(m_stack);
    //level_display.updateGraphics(m_stack);
    //section_display.updateGraphics(m_stack);

    // Apply next piece texture
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int tile = PIECES[m_next][0][j][i];
            if (tile > 0) {
                tile--;

                int tu = tile % (tileset_tex.getSize().x / FILE_TILE_SIZE);
                int tv = tile / (tileset_tex.getSize().x / FILE_TILE_SIZE);

                sf::Vertex* quad = &m_next_vertices[(i + j * SIZE) * 4];

                quad[0].color = sf::Color(255, 255, 255, 255);
                quad[1].color = sf::Color(255, 255, 255, 255);
                quad[2].color = sf::Color(255, 255, 255, 255);
                quad[3].color = sf::Color(255, 255, 255, 255);

                quad[0].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
                quad[1].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
                quad[2].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
                quad[3].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
            } else {
                sf::Vertex* quad = &m_next_vertices[(i + j * SIZE) * 4];

                quad[0].color = sf::Color(0, 0, 0, 0);
                quad[1].color = sf::Color(0, 0, 0, 0);
                quad[2].color = sf::Color(0, 0, 0, 0);
                quad[3].color = sf::Color(0, 0, 0, 0);
            }
        }
    }

    // Apply player's piece texture
    unsigned char alpha = 255;
    if (m_lock > 0) {
        if ((float) m_lock >= 2.0 * (float) m_current_mode->lock(m_level) / 5.0)
            alpha = 210;

        if ((float) m_lock >= 3.0 * (float) m_current_mode->lock(m_level) / 5.0)
            alpha = 160;

        if ((float) m_lock >= 4.0 * (float) m_current_mode->lock(m_level) / 5.0)
            alpha = 128;

        if (m_lock == m_current_mode->lock(m_level))
            alpha = 96;
    }
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int tile = PIECES[m_piece.type][m_piece.orientation][j][i];
            if (tile > 0) {
                tile--;

                int tu = tile % (tileset_tex.getSize().x / FILE_TILE_SIZE);
                int tv = tile / (tileset_tex.getSize().x / FILE_TILE_SIZE);

                sf::Vertex* quad = &m_piece_vertices[(i + j * SIZE) * 4];

                quad[0].color = sf::Color(alpha, alpha, alpha, 255);
                quad[1].color = sf::Color(alpha, alpha, alpha, 255);
                quad[2].color = sf::Color(alpha, alpha, alpha, 255);
                quad[3].color = sf::Color(alpha, alpha, alpha, 255);

                quad[0].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + (m_piece.pos_y - 1 + j) * tile_size);
                quad[1].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + (m_piece.pos_y - 1 + j) * tile_size);
                quad[2].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + ((m_piece.pos_y - 1 + j) + 1) * tile_size);
                quad[3].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + ((m_piece.pos_y - 1 + j) + 1) * tile_size);

                quad[0].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
                quad[1].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
                quad[2].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
                quad[3].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
            } else {
                sf::Vertex* quad = &m_piece_vertices[(i + j * SIZE) * 4];

                quad[0].color = sf::Color(0, 0, 0, 0);
                quad[1].color = sf::Color(0, 0, 0, 0);
                quad[2].color = sf::Color(0, 0, 0, 0);
                quad[3].color = sf::Color(0, 0, 0, 0);
            }
        }
    }

    // Apply ghost piece texture
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            int tile = PIECES[m_piece.type][m_piece.orientation][j][i];
            if (tile > 0) {
                tile--;

                int tu = tile % (tileset_tex.getSize().x / FILE_TILE_SIZE);
                int tv = tile / (tileset_tex.getSize().x / FILE_TILE_SIZE);

                sf::Vertex* quad = &m_ghost_vertices[(i + j * SIZE) * 4];

                quad[0].color = sf::Color(80, 80, 80, 255);
                quad[1].color = sf::Color(80, 80, 80, 255);
                quad[2].color = sf::Color(80, 80, 80, 255);
                quad[3].color = sf::Color(80, 80, 80, 255);

                quad[0].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + (m_ghost_y - 1 + j) * tile_size);
                quad[1].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + (m_ghost_y - 1 + j) * tile_size);
                quad[2].position = sf::Vector2f(pos_x + ((m_piece.pos_x - 2 + i) + 1) * tile_size, pos_y + ((m_ghost_y - 1 + j) + 1) * tile_size);
                quad[3].position = sf::Vector2f(pos_x + (m_piece.pos_x - 2 + i) * tile_size, pos_y + ((m_ghost_y - 1 + j) + 1) * tile_size);

                quad[0].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
                quad[1].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
                quad[2].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
                quad[3].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
            } else {
                sf::Vertex* quad = &m_ghost_vertices[(i + j * SIZE) * 4];

                quad[0].color = sf::Color(0, 0, 0, 0);
                quad[1].color = sf::Color(0, 0, 0, 0);
                quad[2].color = sf::Color(0, 0, 0, 0);
                quad[3].color = sf::Color(0, 0, 0, 0);
            }
        }
    }
}

void PlayerImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    if (m_draw_ghost)
        target.draw(m_ghost_vertices, &tileset_tex);

    if (m_draw_piece)
        target.draw(m_piece_vertices, &tileset_tex);

    target.draw(m_next_vertices, &tileset_tex);

    target.draw(m_score_display);
    target.draw(m_level_display);
    target.draw(m_section_display);
}
