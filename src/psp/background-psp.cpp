#include "../background.h"

void Background::initGraphics() {
    texture = g2dTexLoad("background.png",G2D_SWIZZLE);
}

void Background::draw() {
    g2dBeginRects(texture);

    g2dSetCoordXY(0,0);
    g2dAdd();

    g2dEnd();
}
