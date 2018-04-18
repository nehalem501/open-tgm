/* PlayerImpl.h - GBA */

#ifndef PLAYER_GBA_H
#define PLAYER_GBA_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
