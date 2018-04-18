/* PlayerImpl.h - 3DS */

#ifndef PLAYER_3DS_H
#define PLAYER_3DS_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
