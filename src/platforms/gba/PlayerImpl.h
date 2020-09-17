/* PlayerImpl.h - GBA */

#ifndef PLAYER_GBA_H
#define PLAYER_GBA_H

/* Forward declarations to avoid dependency hell */
class Player;

class PlayerImpl {
    public:
        PlayerImpl(Player& player, Position& position) :
                m_player(player),
                m_position(position) {
        }

        inline void position(Position& position) { m_position = position; }

        void update_piece_type();
        void update_piece_position();
        void update_piece_lock_animation(unsigned int lock, unsigned int max);
        void update_piece_reset_lock();

        void update_ghost_type();
        void update_ghost_position();

        void update_next_type();

        void render() const;

    private:
        Player& m_player;
        Position& m_position;
};

#endif // PLAYER_GBA_H
