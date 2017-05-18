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
        stack1.m_pos_y = 5 * tile_size;
    }

    stack1.updateSize();
    player1.updateSize();

    score_display1.updateSize(&stack1);
    level_display1.updateSize(&stack1);
    level_target_display1.updateSize(&stack1);

    timer1.updateSize(&stack1);
    labels1.updateSize(&stack1);

     // TODO timer2
}

void GameImpl::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    #warning "SFML Game::draw not finished"
    target.draw(player1);
    target.draw(stack1);

    target.draw(score_display1);
    target.draw(level_display1);
    target.draw(level_target_display1);

    target.draw(timer1); // TODO timer2
    target.draw(labels1);

    /*if (p1_start > 50) { //TODO
        target.draw(m_ready);
    } else if (p1_start > 0) {
        target.draw(m_go);
    }*/
}
