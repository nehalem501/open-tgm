/* PlayerImpl.h - PSP */

#ifndef PLAYER_PSP_H
#define PLAYER_PSP_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
