/* PlayerImpl.h - Dummy */

#ifndef PLAYER_DUMMY_H
#define PLAYER_DUMMY_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
