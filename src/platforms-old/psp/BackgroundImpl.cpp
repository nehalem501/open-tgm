/* BackgroundImpl.cpp - PSP */

#include <stdlib.h>
//#include <glib2d.h>
#include "BackgroundImpl.h"

void BackgroundImpl::init_graphics() {
    //m_texture = g2dTexLoad((char *) "resources/background.png", G2D_SWIZZLE);
}

void BackgroundImpl::draw() const {
    if (options) {
        // Draw settings background
        /*g2dBeginQuads(NULL);

        g2dSetColor(G2D_RGBA(0, 0, 0xFF, 0xFF));
        g2dSetCoordXY(0, 0);
        g2dAdd();
        g2dSetCoordXY(G2D_SCR_W, 0);
        g2dAdd();

        g2dSetColor(BLACK);
        g2dSetCoordXY(G2D_SCR_W, G2D_SCR_H);
        g2dAdd();
        g2dSetCoordXY(0, G2D_SCR_H);
        g2dAdd();

        g2dEnd();*/
    } else {
        // Draw game background
        //g2dBeginRects(m_texture);

        /*if (m_texture == NULL)
            g2dSetColor(RED);*/

        //g2dSetCoordXY(0,0);
        //g2dAdd();

        //g2dEnd();
    }
}
