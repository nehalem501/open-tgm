/* Player.h */

#ifndef PLAYER_H
#define PLAYER_H

#include <TargetTypes.h>
#include <Position.h>
#include <Global.h>
#include <Piece.h>
#include <Digits.h>
#include <Grade.h>
#include <Mode.h>
#include <PlayerImpl.h>

/* Forward declarations to avoid dependency hell */
class Stack;

namespace PlayerState {
    enum {
        WAITING = 0,
        ARE,
        NEW_PIECE,
        INGAME,
        LOCK,
        LOCKED_ANIM_OLD,
        LOCKED_ANIM_NEW,
        CLEAR
    };
}

class Player {
    public:
        Player(Position& position) :
            m_current_mode(raw_modes[0]),
            m_implementation(*this, position) { };

        void draw() const;

        #ifdef RESIZABLE
        void resize() {
            m_score_display.resize();
            m_level_display.resize();
            m_section_display.resize();
            m_grade.resize();
            m_implementation.resize();
        }
        #endif

        void init(Position& position, const RawMode *mode);
        void start_game();

        inline void reset_level() {
            m_level = 0;
            m_level_display.set(0);
            //m_level_display.update_graphics(m_stack);
        };

        void update(Stack *stack, int *game_state);

        void change_level(int value, bool line_clear);
        void update_score(unsigned int nb_lines, bool bravo);

        inline void set_combo(int value) { m_combo = value; }

        inline const Piece& piece() { return m_piece; }

        inline bool draw_piece() { return m_draw_piece; }
        inline bool draw_ghost() { return m_draw_ghost; }

        inline tiles_t get_next_piece() { return m_next; }
        inline int get_ghost_y() { return m_ghost_y; }

    private:
        void next_piece();

        bool check_lock();

        inline void reset_lock() {
            #ifdef DEBUG
            print("reset lock\n");
            #endif

            m_start_lock = false;
            m_lock = 1; // 1 instead of 0 because of 20G special case
            m_implementation.update_piece_reset_lock();
        };

        inline void start_lock() { m_start_lock = true; m_lock++; };

        bool check_das_left();
        bool check_das_right();

        unsigned int gravity(bool can_go_down);

        Piece m_piece;

        Digits m_score_display;
        Digits m_level_display;
        Digits m_section_display;

        Grade m_grade;
        uint32_t m_score;
        unsigned int m_level;

        Mode m_current_mode;

        tiles_t m_history[4];

        unsigned int m_active_time, m_gravity, m_section, m_gravity_counter;

        int m_ghost_y, m_piece_old_y, m_lock_color_delay;
        int m_state;

        unsigned int m_are, m_lock, m_combo;
        unsigned int m_sonic, m_soft, m_clear;
        unsigned int m_das_left, m_das_right;

        tiles_t m_next;

        bool m_draw_piece, m_draw_ghost;
        bool m_start_das_left, m_start_das_right;

        bool m_line_are, /*m_start_clear,*/ m_start_lock;
        bool m_previous_down;

        bool m_already_dropped;

        PlayerImpl m_implementation;
};

#endif // PLAYER_H
