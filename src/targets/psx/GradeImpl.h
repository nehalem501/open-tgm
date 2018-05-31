/* GradeImpl.h - PSX */

#ifndef GRADE_PSX_H
#define GRADE_PSX_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
