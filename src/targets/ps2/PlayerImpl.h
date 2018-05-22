/* PlayerImpl.h - PS2 */

#ifndef PLAYER_PS2_H
#define PLAYER_PS2_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
