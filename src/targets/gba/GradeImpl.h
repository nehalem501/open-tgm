/* GradeImpl.h - GBA */

#ifndef GRADE_GBA_H
#define GRADE_GBA_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
