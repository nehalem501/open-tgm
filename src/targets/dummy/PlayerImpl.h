/* PlayerImpl.h - Dummy */

#ifndef PLAYER_DUMMY_H
#define PLAYER_DUMMY_H

/* Forward declarations to avoid dependency hell */
class Player;

class PlayerImpl {
    public:
        void update(const Player& player);
        void render() const;

    private:
        bool m_draw_piece, m_draw_ghost;
};

#endif
