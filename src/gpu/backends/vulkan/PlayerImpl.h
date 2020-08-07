/* PlayerImpl.h - Vulkan */

#ifndef PLAYER_VULKAN_H
#define PLAYER_VULKAN_H

#include <core/Player.h>

class PlayerImpl : public Core::Player {
    public:
        void init_graphics();
        void update_graphics();
        void draw() const;
};

#endif
