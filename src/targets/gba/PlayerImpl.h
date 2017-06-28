/* PlayerImpl.h - GBA */

#ifndef PLAYER_GBA_H
#define PLAYER_GBA_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
