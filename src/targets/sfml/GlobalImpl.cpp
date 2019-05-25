/* globalImpl.cpp - SFML */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
#include <Global.h>

void init_random() {
    // TODO tgm-random
    srand(time(NULL));
}

void init_textures() {
    if (!tileset_tex.loadFromFile("resources/any/tilemap.png")) {
        std::cout << "ERROR loading tilemap texture" << std::endl;
    }

    if (!outline_tex.loadFromFile("resources/any/tilemap2.png")) {
        std::cout << "ERROR loading outline texture" << std::endl;
    }

    if (!frame_tex.loadFromFile("resources/any/frame.png")) {
        std::cout << "ERROR loading frame texture" << std::endl;
    }
    frame_tex.setSmooth(true);

    if (!digits_tex.loadFromFile("resources/any/digits-font.png")) {
        std::cout << "ERROR loading digits texture" << std::endl;
    }

    if (!labels_tex.loadFromFile("resources/any/labels-font.png")) {
        std::cout << "ERROR loading labels texture" << std::endl;
    }

    if (!text_tex.loadFromFile("resources/any/ui-font.png")) {
        std::cout << "ERROR loading text texture" << std::endl;
    }
    text_tex.setSmooth(true);

    //if (!grades_tex.loadFromFile("resources/timer-glyphs.png")) {

    if (!timer_tex.loadFromFile("resources/any/timer-glyphs.png")) {
        std::cout << "ERROR loading timer texture" << std::endl;
    }

    if (!particle_tex.loadFromFile("resources/any/particle.png")) {
        std::cout << "ERROR loading particle texture" << std::endl;
    }
    particle_tex.setSmooth(true);


    #ifdef DEBUG
    std::cout << "Finished loading textures" << std::endl;
    #endif
}
