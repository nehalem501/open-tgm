/* PlayerImpl.h - 3DS */

#ifndef PLAYER_3DS_H
#define PLAYER_3DS_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
