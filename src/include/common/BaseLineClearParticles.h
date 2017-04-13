/* BaseLineClearParticles.h */

#ifndef BASE_LINE_CLEAR_PARTICLES_H
#define BASE_LINE_CLEAR_PARTICLES_H

class BaseLineClearParticles {
    public:
        BaseLineClearParticles();
        void setEmitter(float position_x, float position_y);
        void updateSize(float gamePosX, float gamePosY, float displayTileSize);
        void update();
        void init();
        bool end();
};

#endif

