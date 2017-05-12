/* GlobalSFML.h */

#ifndef GLOBAL_SFML_H
#define GLOBAL_SFML_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

extern sf::Time time_per_frame;

extern sf::Vector2u screen_size;

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
