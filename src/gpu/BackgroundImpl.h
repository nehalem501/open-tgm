/* BackgroundImpl.h - GPU */

#ifndef BACKGROUND_GPU_H
#define BACKGROUND_GPU_H

#include "Sprite.h"

class BackgroundImpl {
    public:
        BackgroundImpl() : m_image(0, 0, 100, 100, NULL) { };
        void render(const bool options) const;

    private:
        Sprite m_image;
};

#endif
