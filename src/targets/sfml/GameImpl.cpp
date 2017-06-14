/* GameImpl.cpp - SFML */

#include <cmath>
#include <Global.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <Stack.h>
#include <Player.h>
#include "GlobalSFML.h"
#include "GameImpl.h"

void GameImpl::updateSize() {
    // TODO

    if (stack_position == StackPosition::CENTERED) {
        stack1.m_pos_x = (screen_size.x / 2) - (stack1.m_width / 2) * tile_size;
        stack1.m_pos_y = 3 * tile_size;
    }

    stack1.updateSize();
    player1.updateSize();

    timer1.updateSize(&stack1);
    labels1.updateSize(&stack1);

     // TODO timer2
}

void GameImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    #warning "SFML Game::draw not finished"
    target.draw(player1);
    target.draw(stack1);

    target.draw(timer1); // TODO timer2
    target.draw(labels1);

    switch (m_player1_state) {
        case GameState::READY_GO:
            target.draw(m_p1_ready_go_string);
            break;

        case GameState::GAME_OVER:
            break;
    }
}
