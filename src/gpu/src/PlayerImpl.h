/* PlayerImpl.h - GPU */

#ifndef PLAYER_GPU_H
#define PLAYER_GPU_H

#include <Shapes.h>
#include "Tilemap.h"

/* Forward declarations to avoid dependency hell */
class Player;

class PlayerImpl {
    public:
        PlayerImpl(Player& player, Position& position);

        inline void position(Position& position) { m_position = position; }

        void update_piece_type();
        void update_piece_position();
        void update_piece_lock_animation(unsigned int lock, unsigned int max);
        inline void update_piece_reset_lock() { m_piece.color(GPU_WHITE); }

        void update_ghost_type();
        void update_ghost_position();

        void update_next_type();

        void render() const;

        #ifdef RESIZABLE
        void resize() {
            m_piece.resize(m_position);
            m_ghost.resize(m_position);
            m_next.resize(m_position);
        }
        #endif

    private:
        Player& m_player;
        Position& m_position;
        Tilemap<PIECE_SIZE * PIECE_SIZE> m_piece;
        Tilemap<PIECE_SIZE * PIECE_SIZE> m_ghost;
        Tilemap<PIECE_SIZE * PIECE_SIZE> m_next;
};

#endif
