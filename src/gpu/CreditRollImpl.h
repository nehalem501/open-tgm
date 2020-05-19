/* CreditRollImpl.h - GPU */

#ifndef CREDIT_ROLL_GPU_H
#define CREDIT_ROLL_GPU_H

class CreditRollImpl {
    public:
        void update();
        void render() const;

        #ifdef RESIZABLE
        void resize() { }
        #endif
};

#endif
