/* BaseGame.h */

#ifndef BASE_GAME_H
#define BASE_GAME_H

#include <Timer.h>
#include <Labels.h>
#include <Text.h>

namespace GameState {
    enum {
        READY_GO = 0,
        INGAME,
        GAME_OVER_ANIM,
        GAME_OVER_TEXT,
        FINISHED
    };
}

const char READY_STR[] = "READY";
const char GO_STR[] = "GO";
const char GAME_OVER_STR[] = "GAME OVER";

class BaseGame {
    public:
        void initGraphics();

        void updateGameLogic();
        void updateGraphics();

        void startPlayer1(int8_t mode);
        void p1_ready_go();
        bool hasPlayer1Finished();

    #ifdef MULTIPLAYER
        void startPlayer2(int8_t mode);
        bool hasPlayer2Finished();
        void startDoubles();
    #endif

        Timer timer1;
        Labels labels1;

    #ifdef MULTIPLAYER
        Timer timer2;
        Labels labels2;
    #endif

    protected:
        int8_t m_player1_state;
        uint8_t m_p1_counter;
        Text m_p1_string;

    #ifdef MULTIPLAYER
        int8_t m_player2_state;
        uint8_t m_p2_counter;
        Text m_p2_string;
    #endif
};

#endif
