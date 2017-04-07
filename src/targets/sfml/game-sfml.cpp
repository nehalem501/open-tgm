/* game-sfml.cpp */

#include <cmath>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "../../common/global.h"
#include "../../common/game.h"


void Game::updateSize(sf::Vector2u screenSize) {
    // TODO

    if (stack_position == Position::CENTERED) {
        stack1.m_pos_x = (screenSize.x / 2) - (stack1.m_width / 2) * tile_size;
        stack1.m_pos_y = 5;
    }

    stack1.updateSize(screenSize);
    player1.updateSize(screenSize);

    //timer1.updateSize(screenSize); // TODO timer2
    //labels1.updateSize(screenSize);
}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    #warning "SFML Game::draw not finished"
    target.draw(player1);
    target.draw(stack1);
    //target.draw(player1);

    target.draw(timer1); // TODO timer2
    target.draw(labels1);
    
    /*if (p1_start > 50) { //TODO
        target.draw(m_ready);
    } else if (p1_start > 0) {
        target.draw(m_go);
    }*/
}
