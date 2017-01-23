/* menu-sfml.cpp */

#include "../menu.h"
#include "../global.h"
#include "../frame.h"
#include "../home.h"


void Menu::initGraphics() {
    m_home.initGraphics();
    m_chooseMode.initGraphics();    
}

void Menu::updateSize(sf::Vector2u windowSize) {
    tile_size = (int) floor(windowSize.y / TILE_RATIO);
    
    background.updateSize(windowSize);

    m_home.updateSize(windowSize);
    // TODO resize modesText[]
    // TODO check for multiplayer
#warning "Multiplayer missing"
    game.updateSize(windowSize);
    frame1.updateSize(windowSize);
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(background);
    switch(m_state) {
        case MenuState::HOME:
            target.draw(m_home);
            break;

        case MenuState::CHOOSE_PLAYER:
            target.draw(frame1);
            //target.draw(dataNotUsed);
            //target.draw(newPlaiyer);
            //target.draw(loadPlayer);
            break;

        case MenuState::CHOOSE_MODE:
            target.draw(frame1);/*
                                   for (unsigned int i = 0; i < modesText.size(); i++) {
                                   target.draw(modesText[i]);
                                   }*/
            target.draw(m_chooseMode);
            break;

        case MenuState::START_GAME:
            target.draw(frame1);
            break;

        case MenuState::INGAME:
            target.draw(frame1);
            // TODO 2 players
            target.draw(game);
            break;

        default:
            break;
    }
}
