/* global.h */

#ifndef GLOBAL_H
#define GLOBAL_H

#include <stdint.h>


class Player;
class Stack;
class Input;
class Game;
class Menu;
class Background;
class Mode;
class Frame;

namespace Position {
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
extern uint8_t stack_position;

extern Player player1;
extern Stack stack1;
extern Frame frame1;

#ifdef MULTIPLAYER
#undef MAX_WIDTH
#define MAX_WIDTH 14
extern Player player2;
extern Stack stack2;
extern Frame frame2;
#endif

#ifdef TARGET_SFML
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
extern sf::Time timePerFrame;

extern sf::Texture tileset_tex;
extern sf::Texture outline_tex;
extern sf::Texture frame_tex;
extern sf::Texture digits_tex;
extern sf::Texture labels_tex;
extern sf::Texture text_tex;
extern sf::Texture grades_tex;
extern sf::Texture timer_tex;
extern int tile_size;
#define TILE_RATIO 29
#define FILE_TILE_SIZE 128
#endif

extern Input input;
extern Game game;
extern Menu menu;
extern Background background;
extern Mode modes[];

void init();
void initTextures();
void initGraphics();
void initRandom();

#endif
