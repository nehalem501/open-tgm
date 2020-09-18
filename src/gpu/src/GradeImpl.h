/* GradeImpl.h - GPU */

#ifndef GRADE_GPU_H
#define GRADE_GPU_H

class GradeImpl {
    public:
        void update();
        void render() const;

        #ifdef RESIZABLE
        void resize() { }
        #endif
};

#endif
