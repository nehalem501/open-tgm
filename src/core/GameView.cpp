/* GameView.cpp */

#include <Position.h>
#include <Debug.h>
#include <Scene.h>
#include <GameView.h>

GameView::GameView() :
    m_player1_position(PLAYER1_POSITION), // TODO
    m_player1_game(m_player1_position)
    #ifdef MULTIPLAYER
    ,
    m_player2_position(PLAYER2_POSITION), // TODO
    m_player2_game(m_player2_position)
    #endif
{
    printd(DebugCategory::SCENE, "GameView constructor");
}

void GameView::update(SceneState& state) {
    m_player1_game.update(state);

    #ifdef MULTIPLAYER
    m_player2_game.update(state);
    #endif
}

void GameView::draw() const {
    m_player1_game.draw();

    #ifdef MULTIPLAYER
    m_player2_game.draw();
    #endif
}
