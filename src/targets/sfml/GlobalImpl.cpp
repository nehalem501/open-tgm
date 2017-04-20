/* globalSFML.cpp */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "GlobalSFML.h"
#include <Global.h>

void initRandom() {
    // TODO tgm-random
    srand(time(NULL));
}

void initTextures() {
    if (!tileset_tex.loadFromFile("resources/tilemap.png")) {
        std::cout << "ERROR loading tilemap texture" << std::endl;
    }

    if (!outline_tex.loadFromFile("resources/tilemap2.png")) {
        std::cout << "ERROR loading outline texture" << std::endl;
    }

    if (!frame_tex.loadFromFile("resources/frame.png")) {
        std::cout << "ERROR loading frame texture" << std::endl;
    }
    frame_tex.setSmooth(true);

    if (!digits_tex.loadFromFile("resources/digits-font.png")) {
        std::cout << "ERROR loading digits texture" << std::endl;
    }

    if (!labels_tex.loadFromFile("resources/labels-font.png")) {
        std::cout << "ERROR loading labels texture" << std::endl;
    }

    if (!text_tex.loadFromFile("resources/ui-font.png")) {
        std::cout << "ERROR loading text texture" << std::endl;
    }

    //if (!grades_tex.loadFromFile("resources/timer-glyphs.png")) {

    if (!timer_tex.loadFromFile("resources/timer-glyphs.png")) {
        std::cout << "ERROR loading timer texture" << std::endl;
    }

    std::cout << "Finished loading textures" << std::endl;
}
