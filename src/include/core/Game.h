/* Game.h */

#ifndef CORE_GAME_H
#define CORE_GAME_H

#include <Timer.h>
#include <Labels.h>
#include <Text.h>

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

namespace Core {
    class Game {
        public:
            void init_graphics();

            void update(int *state);
            void update_graphics();

            void start_p1(int mode);
            void p1_ready_go();
            bool has_p1_finished();

        #ifdef MULTIPLAYER
            void start_p2(int mode);
            bool has_p2_inished();
            void startDoubles();
        #endif

            ::Timer m_timer1;
            ::Labels m_labels1;

        #ifdef MULTIPLAYER
            ::Timer m_timer2;
            ::Labels m_labels2;
        #endif

        protected:
            int m_p1_state;
            uint8_t m_p1_counter;
            ::Text m_p1_string;

        #ifdef MULTIPLAYER
            int m_p2_state;
            uint8_t m_p2_counter;
            ::Text m_p2_string;
        #endif
    };
}

#endif
