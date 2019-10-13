/* Game.h */

#ifndef GAME_H
#define GAME_H

#include <Position.h>
#include <Timer.h>
#include <Labels.h>
#include <Text.h>
#include <Stack.h>
#include <Player.h>
#include <Frame.h>

namespace GameState {
    enum {
        READY_GO = 0,
        INGAME,
        CREDIT_ROLL,
        GAME_OVER_ANIM,
        GAME_OVER_TEXT,
        FINISHED
    };
}

const char READY_STR[] = "READY";
const char GO_STR[] = "GO";
const char GAME_OVER_STR[] = "GAME OVER";

class Game {
    public:
        Game();

        void draw();

        void init_graphics();

        void update(int *state);
        void update_graphics();

        void start_p1(int mode);
        void p1_ready_go();
        bool has_p1_finished();

        #ifdef MULTIPLAYER
        void start_p2(int mode);
        bool has_p2_inished();
        void start_doubles();
        #endif

    private:
        Position m_p1_position;
        Player m_p1;
        Stack m_p1_stack;
        Frame m_p1_frame;
        Text m_p1_string;
        Timer m_p1_timer;
        Labels m_p1_labels;
        int m_p1_state;
        uint8_t m_p1_counter;

        #ifdef MULTIPLAYER
        Position m_p2_position;
        Player m_p2;
        Stack m_p2_stack;
        Frame m_p2_frame;
        Text m_p2_string;
        Timer m_p2_timer;
        Labels m_p2_labels;
        int m_p2_state;
        uint8_t m_p2_counter;
        #endif
};

#endif // GAME_H
