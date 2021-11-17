/* Reloadable.h - GPU */

#ifndef RELOADABLE_H
#define RELOADABLE_H

class Reloadable {
    public:
        virtual void refresh() = 0;
};

void register_reloadable(Reloadable* item);

#endif // RELOADABLE_H
