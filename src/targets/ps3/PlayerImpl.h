/* PlayerImpl.h - PS3 */

#ifndef PLAYER_PS3_H
#define PLAYER_PS3_H

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
