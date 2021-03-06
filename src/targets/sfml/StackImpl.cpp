/* StackImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Shapes.h>
#include "GlobalSFML.h"
#include "StackImpl.h"

void StackImpl::init_graphics() {
    // Init stack vertices
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize((std::size_t) (m_width * m_height * 4));

    for (std::size_t i = 0; i < m_vertices.getVertexCount(); i++) {
        m_vertices[i].color = sf::Color(0, 0, 0, 0);
    }

    // Init outline vertices
    m_vertices_outline.setPrimitiveType(sf::Quads);
    m_vertices_outline.resize((std::size_t) (m_width * m_height * 4));

    for (std::size_t i = 0; i < m_vertices_outline.getVertexCount(); i++) {
        m_vertices_outline[i].color = sf::Color(0, 0, 0, 0);
    }
}

void StackImpl::resize() {
    // Update stack tiles and outline position
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            // get a pointer to the current stack tile quad
            sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];
            quad[0].position = sf::Vector2f(m_pos_x + i * tile_size, m_pos_y + j * tile_size);
            quad[1].position = sf::Vector2f(m_pos_x + (i + 1) * tile_size, m_pos_y + j * tile_size);
            quad[2].position = sf::Vector2f(m_pos_x + (i + 1) * tile_size, m_pos_y + (j + 1) * tile_size);
            quad[3].position = sf::Vector2f(m_pos_x + i * tile_size, m_pos_y + (j + 1) * tile_size);

            // get a pointer to the current outline tile quad
            quad = &m_vertices_outline[(i + j * m_width) * 4];
            quad[0].position = sf::Vector2f(m_pos_x + i * tile_size, m_pos_y + j * tile_size);
            quad[1].position = sf::Vector2f(m_pos_x + (i + 1) * tile_size, m_pos_y + j * tile_size);
            quad[2].position = sf::Vector2f(m_pos_x + (i + 1) * tile_size, m_pos_y + (j + 1) * tile_size);
            quad[3].position = sf::Vector2f(m_pos_x + i * tile_size, m_pos_y + (j + 1) * tile_size);
        }
    }
}

void StackImpl::update_graphics() {
    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        if (m_part[i].is_active()) {
            m_part[i].update();
        }
    }

    unsigned char rgb = 200;
    //unsigned char alpha = 255;

    // Apply Stack tiles and outline texture
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            // Outline
            int tile = m_outline[i + j * m_width];
            sf::Vertex* quad = &m_vertices_outline[(i + j * m_width) * 4];
            assign_tile(tile, 255, 144, quad);

            // Stack
            tile = m_field[i + j * m_width];
            quad = &m_vertices[(i + j * m_width) * 4];
            if (tile & Block::BLINK_BIT) {
                tile = Block::BLINK;
                rgb = 255;
            } else {
                rgb = 200;
            }
            assign_tile(tile, rgb, 255, quad);
        }
    }
}

void StackImpl::assign_tile(int tile, unsigned char rgb, unsigned char alpha, sf::Vertex* quad) {
    int tu = tile % (tileset_tex.getSize().x / FILE_TILE_SIZE);
    int tv = tile / (tileset_tex.getSize().x / FILE_TILE_SIZE);

    quad[0].color = sf::Color(rgb, rgb, rgb, alpha);
    quad[1].color = sf::Color(rgb, rgb, rgb, alpha);
    quad[2].color = sf::Color(rgb, rgb, rgb, alpha);
    quad[3].color = sf::Color(rgb, rgb, rgb, alpha);

    quad[0].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
    quad[1].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, tv * FILE_TILE_SIZE);
    quad[2].texCoords = sf::Vector2f((tu + 1) * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
    quad[3].texCoords = sf::Vector2f(tu * FILE_TILE_SIZE, (tv + 1) * FILE_TILE_SIZE);
}

void StackImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_vertices, &tileset_tex);
    target.draw(m_vertices_outline, &outline_tex);

    for (unsigned int i = 0; i < FILLED_LINES_NB; i++) {
        target.draw(m_part[i]);
    }
}
