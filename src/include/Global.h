/* Global.h */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <TargetTypes.h>
#include <Size.h>
#include <Input.h>
#include <Mode.h>

#define MAX_WIDTH  10
#define MAX_HEIGHT 22

#define OUTLINE_LEFT  0x1   // 0b0001
#define OUTLINE_RIGHT 0x2   // 0b0010
#define OUTLINE_UP    0x4   // 0b0100
#define OUTLINE_DOWN  0x8   // 0b1000

extern uint32_t rand_seed;
extern unsigned int stack_position;

extern Input input;
extern Mode* modes[];
extern Size screen;

void init_random(); // TODO

#endif // GLOBAL_H
