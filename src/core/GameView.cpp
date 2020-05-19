/* GameView.cpp */

#include <Position.h>
#include <GameView.h>

GameView::GameView() :
    m_player1_position(Position(2 * tile_size, 2 * tile_size)), // TODO
    m_player1(m_player1_position)
    #ifdef MULTIPLAYER
    ,
    m_player2_position(Position(15, 0)),
    m_player2(m_player2_position)
    #endif
{
    #ifdef DEBUG
    print("GameView constructor\n");
    #endif
}

void GameView::update(int *state) {
    m_player1.update(state);

    #ifdef MULTIPLAYER
    m_player2.update(state);
    #endif
}

void GameView::draw() const {
    m_player1.draw();

    #ifdef MULTIPLAYER
    m_player2.draw();
    #endif
}
