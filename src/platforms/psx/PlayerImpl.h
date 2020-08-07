/* PlayerImpl.h - PSX */

#ifndef PLAYER_PSX_H
#define PLAYER_PSX_H

/* Forward declarations to avoid dependency hell */
class Player;

class PlayerImpl {
    public:
        PlayerImpl(Player& player) : m_player(player) { };
        void update();
        void render() const;

    private:
        Player& m_player;
};

#endif
