/* PlayerImpl.h - SDL2 */

#ifndef PLAYER_SDL2_H
#define PLAYER_SDL2_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
