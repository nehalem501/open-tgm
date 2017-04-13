/* stack-sfml.cpp */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../../common/stack.h"


void Stack::initGraphics() {
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

void Stack::updateSize(sf::Vector2u screenSize) {
    // Update board position
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            // get a pointer to the current tile's quad
            sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];

            quad[0].position = sf::Vector2f(m_pos_x + i * tile_size, m_pos_y + j * tile_size);
            quad[1].position = sf::Vector2f(m_pos_x + (i + 1) * tile_size, m_pos_y + j * tile_size);
            quad[2].position = sf::Vector2f(m_pos_x + (i + 1) * tile_size, m_pos_y + (j + 1) * tile_size);
            quad[3].position = sf::Vector2f(m_pos_x + i * tile_size, m_pos_y + (j + 1) * tile_size);
        }
    }        
}

void Stack::updateGraphics() {
    /*switch (m_nb_part) {
        case 1:
            m_part0.update();
            if (m_part0.end())
                m_nb_part = 0;
            break;

        case 2:
            m_part0.update();
            m_part1.update();
            if (m_part0.end())
                m_nb_part = 0;
            break;

        case 3:
            m_part0.update();
            m_part1.update();
            m_part2.update();
            if (m_part0.end())
                m_nb_part = 0;
            break;

        case 4:
            m_part0.update();
            m_part1.update();
            m_part2.update();
            m_part3.update();
            if (m_part0.end())
                m_nb_part = 0;
            break;
    }*/
    
    int tileSize = 128;

    unsigned char rgb = 200;
    //unsigned char alpha = 255;

    // Apply Board texture
    for (int i = 0; i < m_width; ++i) {
        for (int j = 0; j < m_height; ++j) {
            int tile = m_stack[i + j * m_width];
            if (tile > 0) {
                if (tile == 8) {
                    rgb = 255;
                    //cout << "tile8" << endl;
                } else {
                    rgb = 200;
                }
                tile--;

                int tu = tile % (tileset_tex.getSize().x / tileSize);
                int tv = tile / (tileset_tex.getSize().x / tileSize);

                sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];

                quad[0].color = sf::Color(rgb, rgb, rgb, 255);
                quad[1].color = sf::Color(rgb, rgb, rgb, 255);
                quad[2].color = sf::Color(rgb, rgb, rgb, 255);
                quad[3].color = sf::Color(rgb, rgb, rgb, 255);

                quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
                quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
            } else {
                sf::Vertex* quad = &m_vertices[(i + j * m_width) * 4];

                quad[0].color = sf::Color(0, 0, 0, 0);
                quad[1].color = sf::Color(0, 0, 0, 0);
                quad[2].color = sf::Color(0, 0, 0, 0);
                quad[3].color = sf::Color(0, 0, 0, 0);
            }
        }
    }
}

void Stack::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_vertices, &tileset_tex);
    target.draw(m_vertices_outline, &tileset_tex);

    switch (m_active_particles) {
        case 1:
            target.draw(m_part0);
            break;

        case 2:
            target.draw(m_part0);
            target.draw(m_part1);
            break;

        case 3:
            target.draw(m_part0);
            target.draw(m_part1);
            target.draw(m_part2);
            break;

        case 4:
            target.draw(m_part0);
            target.draw(m_part1);
            target.draw(m_part2);
            target.draw(m_part3);
            break;
    }
}

