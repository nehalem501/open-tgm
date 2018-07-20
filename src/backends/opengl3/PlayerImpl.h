/* PlayerImpl.h - OpenGL3 */

#ifndef PLAYER_OPENGL3_H
#define PLAYER_OPENGL3_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
