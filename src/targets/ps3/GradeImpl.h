/* GradeImpl.h - PS3 */

#ifndef GRADE_PS3_H
#define GRADE_PS3_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
