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
        stack1.m_pos_x = (screen_size.x / 2) - (stack1.m_width / 2) * tile_size;
        stack1.m_pos_y = 3 * tile_size;
    }

    stack1.resize();
    player1.resize();

    m_timer1.resize(&stack1);
    m_labels1.resize(&stack1);

     // TODO timer2
}

void GameImpl::draw(sf::RenderTarget& target, sf::RenderStates) const {
    target.draw(m_p1);
    target.draw(m_p1_stack);

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
