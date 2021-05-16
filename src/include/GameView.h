/* GameView.h */

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <Game.h>

// TODO
#define PLAYER1_POSITION Position(1 * tile_size, 2.5 * tile_size)

class GameView {
    public:
        GameView();

        void draw() const;

        #ifdef RESIZABLE
        void resize() {
            // TODO layout code
            m_player1_position = PLAYER1_POSITION;
            //print("GameView x: %d, y:%d\n", m_player1_position.x, m_player1_position.y);
            m_player1_game.resize();

            #ifdef MULTIPLAYER
            m_player2_game.resize();
            #endif
        }
        #endif

        void update(int *state);

    private:
        Position m_player1_position;
        Game m_player1_game;

        #ifdef MULTIPLAYER
        Position m_player2_position;
        Game m_player2_game;
        #endif
};

#endif // GAME_VIEW_H
