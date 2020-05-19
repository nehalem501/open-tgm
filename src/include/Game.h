/* Game.h */

#ifndef GAME_H
#define GAME_H

#include <stdint.h>
#include <Position.h>
#include <ChooseMode.h>
#include <Timer.h>
#include <Labels.h>
#include <Text.h>
#include <Stack.h>
#include <Player.h>
#include <Frame.h>

namespace GameState {
    enum {
        CHOOSE_MODE = 0,
        READY_GO,
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
        Game(Position &position);

        void draw() const;

        #ifdef RESIZABLE
        void resize() {
            m_choose_mode.resize(m_position);
            m_player.resize();
            m_stack.resize();
            m_frame.resize();
            m_string.resize(m_position);
            m_timer.resize();
            m_labels.resize();
        }
        #endif

        void update(int *state);
        void update_graphics();

        void start(int mode);
        void ready_go();
        bool has_ended();

    private:
        Position &m_position;
        ChooseMode m_choose_mode;
        Player m_player;
        Stack m_stack;
        Frame m_frame;
        Text m_string; // TODO
        Timer m_timer;
        Labels m_labels;
        int m_state;
        uint8_t m_counter; // TODO
};

#endif // GAME_H
