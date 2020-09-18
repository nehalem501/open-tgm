/* BackgroundImpl.h - GPU */

#ifndef BACKGROUND_GPU_H
#define BACKGROUND_GPU_H

#include "Rect.h"
#include "Image.h"

class BackgroundImpl {
    public:
        BackgroundImpl();

        void render(const bool options) const;

        #ifdef RESIZABLE
        void resize() { } // TODO
        #endif

    private:
        Rect m_background_gradient;
        Image m_background_image;
};

#endif
