/* PlayerImpl.h - PSVita */

#ifndef PLAYER_PSVITA_H
#define PLAYER_PSVITA_H

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
