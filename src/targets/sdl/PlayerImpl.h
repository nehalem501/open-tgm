/* PlayerImpl.h - SDL */

#ifndef PLAYER_SDL_H
#define PLAYER_SDL_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
