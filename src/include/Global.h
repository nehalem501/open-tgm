/* Global.h */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <TargetTypes.h>

/* Forward declarations to avoid dependency hell */
class Mode;
class PlayerImpl;
class StackImpl;
class InputImpl;
class GameImpl;
class MainMenuImpl;
class BackgroundImpl;
class FrameImpl;
typedef PlayerImpl Player;
typedef StackImpl Stack;
typedef InputImpl Input;
typedef GameImpl Game;
typedef MainMenuImpl MainMenu;
typedef BackgroundImpl Background;
typedef FrameImpl Frame;

namespace StackPosition {
    enum {
        CENTERED = 0,
        DIVIDED
    };
}

#define MAX_WIDTH 10
#define MAX_HEIGHT 22

#define OUTLINE_LEFT 0x1    // 0b0001
#define OUTLINE_RIGHT 0x2   // 0b0010
#define OUTLINE_UP 0x4      // 0b0100
#define OUTLINE_DOWN 0x8    // 0b1000

extern uint32_t rand_seed;
extern unsigned int stack_position;

extern Input input;
extern Mode* modes[];
extern MainMenu menu;

void init();
void init_textures();
void init_random();

#endif
