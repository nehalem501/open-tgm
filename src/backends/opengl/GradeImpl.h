/* GradeImpl.h - OpenGL */

#ifndef GRADE_OPENGL_H
#define GRADE_OPENGL_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
