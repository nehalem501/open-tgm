/* timer-sfml.cpp */

#include "../global.h"
#include "../timer.h"


void Timer::initGraphics() {
    m_timer_vert.setPrimitiveType(sf::Quads);
    m_timer_vert.resize(8 * 4);
}

void Timer::updateGraphics() {
    for (int i = 0; i < 8; i++) {
        int tile;

        if (i == 2 || i == 5) {
            tile = 10;
        } else if (i > 2 && i < 5) {
            tile = str[i-1];
        } else if (i > 5) {
            tile = str[i-2];
        } else {
            tile = str[i];
        }

        int tu = tile % (timer_tex.getSize().x / 90);
        int tv = tile / (timer_tex.getSize().x / 90);

        sf::Vertex* quad = &m_timer_vert[i * 4];

        quad[0].texCoords = sf::Vector2f(tu * 102.0f, tv * 160.0f);
        quad[1].texCoords = sf::Vector2f((tu + 1) * 102.0f, tv * 160.0f);
        quad[2].texCoords = sf::Vector2f((tu + 1) * 102.0f, (tv + 1) * 160.0f);
        quad[3].texCoords = sf::Vector2f(tu * 102.0f, (tv + 1) * 160.0f);
    }
}

void Timer::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_timer_vert, &timer_tex);
}
