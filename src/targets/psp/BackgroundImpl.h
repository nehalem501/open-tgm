/* BackgroundImpl.h - PSP */

#ifndef BACKGROUND_PSP_H
#define BACKGROUND_PSP_H

#include <glib2d.h>
#include <core/Background.h>

class BackgroundImpl : public Core::Background {
    public:
        void initGraphics();
        void draw() const;

    private:
        g2dTexture *m_texture;
};

#endif
