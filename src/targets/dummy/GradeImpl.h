/* GradeImpl.h - Dummy */

#ifndef GRADE_DUMMY_H
#define GRADE_DUMMY_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
