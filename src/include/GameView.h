/* GameView.h */

#ifndef GAME_VIEW_H
#define GAME_VIEW_H

#include <Game.h>

class GameView {
    public:
        GameView();

        void draw() const;

        #ifdef RESIZABLE
        void resize() { m_player1.resize(); }
        #endif

        void update(int *state);

    private:
        Position m_player1_position;
        Game m_player1;

        #ifdef MULTIPLAYER
        Position m_player2_position;
        Game m_player2;
        #endif
};

#endif // GAME_VIEW_H
