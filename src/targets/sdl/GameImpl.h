/* GameImpl.h - SDL */

#ifndef GAME_SDL_H
#define GAME_SDL_H

#include <core/Game.h>

class GameImpl : public Core::Game {
    public:
        void draw() const;
};

#endif
