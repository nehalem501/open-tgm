/* GradeImpl.h - 3DS */

#ifndef GRADE_3DS_H
#define GRADE_3DS_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
