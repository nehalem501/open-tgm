/* PlayerImpl.h - PSX */

#ifndef PLAYER_PSX_H
#define PLAYER_PSX_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
