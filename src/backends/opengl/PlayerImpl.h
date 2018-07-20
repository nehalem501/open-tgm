/* PlayerImpl.h - OpenGL */

#ifndef PLAYER_OPENGL_H
#define PLAYER_OPENGL_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
