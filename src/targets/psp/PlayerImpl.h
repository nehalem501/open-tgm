/* PlayerImpl.h - PSP */

#ifndef PLAYER_PSP_H
#define PLAYER_PSP_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void initGraphics();
        void updateGraphics();
        void draw() const;
};

#endif
