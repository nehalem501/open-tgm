/* PlayerImpl.h - PS3 */

#ifndef PLAYER_PS3_H
#define PLAYER_PS3_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
