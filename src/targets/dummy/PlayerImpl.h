/* PlayerImpl.h - Dummy */

#ifndef PLAYER_DUMMY_H
#define PLAYER_DUMMY_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
