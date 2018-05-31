/* GradeImpl.h - PS2 */

#ifndef GRADE_PS2_H
#define GRADE_PS2_H

#include <core/Grade.h>

class GradeImpl : public Core::Grade {
    public:
        void init_graphics();
        void draw() const;
};

#endif
