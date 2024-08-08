/* GameView.cpp */

#include <Position.h>
#include <Debug.h>
#include <Scene.h>
#include <GameView.h>

GameView::GameView() :
    #ifdef RESIZABLE
    m_player1_position(PLAYER1_POSITION), // TODO
    m_player1_game(m_player1_position)
    #else
    m_player1_position(Position(1, 3)), // TODO
    m_player1_game(m_player1_position)
    #endif
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
