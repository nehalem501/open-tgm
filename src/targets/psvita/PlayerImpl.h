/* PlayerImpl.h - PSVita */

#ifndef PLAYER_PSVITA_H
#define PLAYER_PSVITA_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
