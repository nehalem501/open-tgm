/* FrameImpl.cpp - SFML */

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include "GlobalSFML.h"
#include "FrameImpl.h"

void FrameImpl::initGraphics() {
    m_background.setFillColor(sf::Color(0, 0, 0, 180));

    m_frame.setPrimitiveType(sf::Quads);

    sf::Vertex v;
    //v.color = sf::Color(255, 255, 255, 255);
    v.color = sf::Color(215, 224, 255, 255);
    v.position = sf::Vector2f(0, 0);

    // Right
    v.texCoords = sf::Vector2f(0, 128);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(128, 128);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(128, 512);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(0, 512);
    m_frame.append(v);

    // Top
    v.texCoords = sf::Vector2f(128, 0);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(128, 128);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(0, 128);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(0, 0);
    m_frame.append(v);

    // Bottom
    v.texCoords = sf::Vector2f(128, 384);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(128, 512);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(0, 512);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(0, 384);
    m_frame.append(v);

    // Left
    v.texCoords = sf::Vector2f(0, 0);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(128, 0);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(128, 384);
    m_frame.append(v);
    v.texCoords = sf::Vector2f(0, 384);
    m_frame.append(v);
}

void FrameImpl::updateGraphics() {
}

void FrameImpl::updateSize(Stack *stack) {
    int width = stack->m_width;
    int height = stack->m_height;
    int pos_x = stack->m_pos_x;
    int pos_y = stack->m_pos_y;

    // Resize background
    m_background.setSize(sf::Vector2f(width * tile_size, height * tile_size));
    m_background.setPosition(pos_x, pos_y + tile_size);

    // Update frame
    // Right
    m_frame[0].position = sf::Vector2f(pos_x + width * tile_size, pos_y + tile_size * 2);
    m_frame[1].position = sf::Vector2f(pos_x + (width + 1) * tile_size, pos_y + tile_size);
    m_frame[2].position = sf::Vector2f(pos_x + (width + 1) * tile_size, pos_y + (height + 1) * tile_size);
    m_frame[3].position = sf::Vector2f(pos_x + width * tile_size, pos_y + height * tile_size);

    // Top
    m_frame[4].position = sf::Vector2f(pos_x - tile_size, pos_y + tile_size);
    m_frame[5].position = sf::Vector2f(pos_x + (width + 1) * tile_size, pos_y + tile_size);
    m_frame[6].position = sf::Vector2f(pos_x + width * tile_size, pos_y + 2 * tile_size);
    m_frame[7].position = sf::Vector2f(pos_x, pos_y + 2 * tile_size);

    // Bottom
    m_frame[8].position = sf::Vector2f(pos_x, pos_y + height * tile_size);
    m_frame[9].position = sf::Vector2f(pos_x + width * tile_size, pos_y + height * tile_size);
    m_frame[10].position = sf::Vector2f(pos_x + (width + 1) * tile_size, pos_y + (height + 1) * tile_size);
    m_frame[11].position = sf::Vector2f(pos_x - tile_size, pos_y + (height + 1) * tile_size);

    // Left
    m_frame[12].position = sf::Vector2f(pos_x - tile_size, pos_y + tile_size);
    m_frame[13].position = sf::Vector2f(pos_x, pos_y + 2 * tile_size);
    m_frame[14].position = sf::Vector2f(pos_x, pos_y + height * tile_size);
    m_frame[15].position = sf::Vector2f(pos_x - tile_size, pos_y + (height + 1) * tile_size);

}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_background);
    target.draw(m_frame, &frame_tex);
}
