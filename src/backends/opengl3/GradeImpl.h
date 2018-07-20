/* GradeImpl.h - OpenGL3 */

#ifndef GRADE_OPENGL3_H
#define GRADE_OPENGL3_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
