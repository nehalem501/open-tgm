/* Global.h */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <TargetTypes.h>
#include <Size.h>
#include <Input.h>

/* Forward declarations to avoid dependency hell */
struct RawMode;

extern const RawMode* raw_modes[];

extern uint32_t rand_seed;
extern unsigned int stack_position;

extern Input input;
extern Size screen;

void init_random(); // TODO

#endif // GLOBAL_H
