/* GameImpl.h - SDL2 */

#ifndef GAME_SDL2_H
#define GAME_SDL2_H

#include <core/Game.h>

class GameImpl : public Core::Game {
    public:
        void draw() const;
};

#endif
