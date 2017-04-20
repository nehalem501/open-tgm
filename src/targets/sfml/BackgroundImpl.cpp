/* BackgroundImpl.cpp - SFML */

#include <iostream>
#include <SFML/Graphics.hpp>
#include "BackgroundImpl.h"

using namespace std;

void BackgroundImpl::initGraphics() {
    if (!image.loadFromFile("resources/background.png")) {
        // ERROR
        std::cout << "ERROR loading background.png" << std::endl;
    }

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(4);

    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(512, 0);
    m_vertices[2].position = sf::Vector2f(512, 512);
    m_vertices[3].position = sf::Vector2f(0, 512);

    m_vertices[0].color = sf::Color::Black;
    m_vertices[1].color = sf::Color::Black;
    m_vertices[2].color = sf::Color::Blue;
    m_vertices[3].color = sf::Color::Blue;

    unsigned int size = sf::Texture::getMaximumSize();
    //unsigned int size = 16;
    imageSize = image.getSize();
    for (unsigned int i = 0; i < image.getSize().x; i += size) {
        for (unsigned int j = 0; j < image.getSize().y; j += size) {
            sf::Texture texture;
            texture.loadFromImage(image, sf::IntRect((int) i, (int) j, (int) size, (int) size));
            textures.push_back(texture);

            BackgroundSprite b;
            sf::Sprite s(textures.back());
            b.sprite = s;
            b.sprite.setPosition(i, j);
            b.x = i;
            b.y = j;

            sprites.push_back(b);
        }
    }
}

void BackgroundImpl::updateSize(sf::Vector2u screenSize) {
    m_vertices[0].position = sf::Vector2f(0, 0);
    m_vertices[1].position = sf::Vector2f(screenSize.x, 0);
    m_vertices[2].position = sf::Vector2f(screenSize.x, screenSize.y);
    m_vertices[3].position = sf::Vector2f(0, screenSize.y);

    float bx = (float) screenSize.x / imageSize.x;
    float by = (float) screenSize.y / imageSize.y;
    float scale;
    if (bx < by) {
        scale = by;
    }
    else {
        scale = bx;
    }

    float pos_x0 = ((float) screenSize.x) / 2.0f - (((float) imageSize.x * scale) / 2.0f);
    float pos_y0 = ((float) screenSize.y) / 2.0f - (((float) imageSize.y * scale) / 2.0f);

    for (std::list<BackgroundSprite>::iterator it = sprites.begin(); it != sprites.end(); ++it) {
        it->sprite.setScale(scale, scale);
        sf::Vector2f position = it->sprite.getPosition();
        //position.x = ((float) screenSize.x) / 2.0f - ((position.x * scale) / 2.0f);
        position.x = pos_x0 + (it->x * scale);
        position.y = pos_y0 + (it->y * scale);
        it->sprite.setPosition(position);
    }
}

void BackgroundImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (options) {
        target.draw(m_vertices);
    } else {
        for (std::list<BackgroundSprite>::const_iterator it = sprites.begin(); it != sprites.end(); ++it) {
            target.draw(it->sprite);
        }
    }
}
