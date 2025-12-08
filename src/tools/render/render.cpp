/* render.cpp - Tool for generating textures files and associated headers */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <unordered_map>
#include <canvas_ity.hpp>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_FAILURE_USERMSG
#include "stb_image.h"

#include "../graphics/Graphics.h"
#include "../graphics/GraphicsCommon.h"

void exit_error(std::string error_msg) {
    std::cout << error_msg << std::endl;
    exit(EXIT_FAILURE);
}

extern "C" void run() {
    const size_t tile_nb = 16;
    BlocksSwatch grey = {
        { 1, 1, 1, 1 },
        { 0.76, 0.76, 0.76, 1 },
        { 0.24, 0.24, 0.24, 1 }
    };
    Buffer b = draw_block_colored(8, grey);

    canvas_ity::canvas context(8, 8 * tile_nb);

    int x = 0;
    int y = 0;

    for (uint16_t i = 0; i < tile_nb; i++) {
        context.put_image_data(b.data, 8, 8, 8 * 4, x, y);
    }
}
