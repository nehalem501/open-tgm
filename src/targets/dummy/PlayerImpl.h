/* PlayerImpl.h - Dummy */

#ifndef PLAYER_DUMMY_H
#define PLAYER_DUMMY_H

#include <common/BasePlayer.h>

class PlayerImpl : public BasePlayer {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
