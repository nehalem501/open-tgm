/* GameImpl.cpp - SFML */

#include <cmath>
#include <Global.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <Player.h>
#include "GlobalSFML.h"
#include "GameImpl.h"

void GameImpl::resize() {
    // TODO

    if (stack_position == StackPosition::CENTERED) {
        m_p1_stack->m_pos_x = (screen_size.x / 2) - (m_p1_stack->m_width / 2) * tile_size;
        m_p1_stack->m_pos_y = 3 * tile_size;
    }

    m_p1_stack->resize();
    m_p1.resize();

    m_p1_timer.resize(m_p1_stack);
    m_p1_labels.resize(m_p1_stack);

     // TODO timer2
}

void GameImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_p1);
    target.draw(*m_p1_stack);

    target.draw(m_p1_timer); // TODO timer2
    target.draw(m_p1_labels);

    switch (m_p1_state) {
        case GameState::READY_GO:
            target.draw(m_p1_string);
            break;

        case GameState::GAME_OVER_ANIM:
            break;

        case GameState::GAME_OVER_TEXT:
            target.draw(m_p1_string);
            break;
    }
}
