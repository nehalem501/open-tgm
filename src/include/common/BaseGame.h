/* BaseGame.h */

#ifndef BASE_GAME_H
#define BASE_GAME_H

#include <Timer.h>
#include <Labels.h>
#include <Digits.h>

namespace GameState {
    enum {
        READY_GO = 0,
        INGAME,
        GAME_OVER,
        FINISHED
    };
}

class BaseGame {
    public:
        void initGraphics();

        void updateGameLogic();
        void updateGraphics();

        void startPlayer1();
        bool hasPlayer1Finished();

    #ifdef MULTIPLAYER
        void startPlayer2();
        bool hasPlayer2Finished();
        void startDoubles();
    #endif

        Timer timer1;
        Labels labels1;
        Digits level_display1;
        Digits level_target_display1;

    #ifdef MULTIPLAYER
        Timer timer2;
        Labels labels2;
        Digits level_display2;
        Digits level_target_display2;
    #endif

    protected:
        int8_t m_player1_state, m_player2_state;
};

#endif