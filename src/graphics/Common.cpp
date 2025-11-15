/* Common.cpp - Graphics */

#include <string.h>
#include <algorithm>
#define CANVAS_ITY_IMPLEMENTATION
#include <canvas_ity.hpp>
#include "GraphicsCommon.h"

/*void insert_image(Position& position, Image& source, Image& destination) {
    for (size_t y = 0; y < source.height; y++) {
        memcpy(
            &destination.buffer.data[position.x + position.y * destination.width],
            &source.buffer.data[source.width * y],
            source.width);
    }
}

void fill_image(Position& position, Size& size, Image& destination) {
    for (size_t y = 0; y < size.height; y++) {
        memcpy(
            &destination.buffer.data[position.x + position.y * destination.width],
            ,
            size.width);
    }
}*/

ColorHSL Color::to_hsl() {
    float min_color = std::min({r, g, b}); // Min. value of RGB
    float max_color = std::max({r, g, b}); // Max. value of RGB
    float delta_max = max_color - min_color; // Delta RGB value

    ColorHSL hsl;

    hsl.a = a;
    hsl.l = (max_color + min_color) / 2.0f;

    if (delta_max == 0) { // This is a gray, no chroma...
        hsl.h = 0;
        hsl.s = 0;
    } else { // Chromatic data...
        if (hsl.l < 0.5) {
            hsl.s = delta_max / (max_color + min_color);
        } else {
            hsl.s = delta_max / (2.0f - max_color - min_color);
        }

        float delta_r = (((max_color - r) / 6.0f) + (delta_max / 2.0f)) / delta_max;
        float delta_g = (((max_color - g) / 6.0f) + (delta_max / 2.0f)) / delta_max;
        float delta_b = (((max_color - b) / 6.0f) + (delta_max / 2.0f)) / delta_max;

        if (r == max_color) {
            hsl.h = delta_b - delta_g;
        } else if (g == max_color) {
            hsl.h = ( 1.0f / 3.0f ) + delta_r - delta_b;
        } else if (b == max_color) {
            hsl.h = ( 2.0f / 3.0f ) + delta_g - delta_r;
        }

        if (hsl.h < 0.0f) {
            hsl.h += 1.0f;
        }
        if (hsl.h > 1.0f) {
            hsl.h -= 1.0f;
        }
    }

    return hsl;
}

static float hue_to_rgb(float v1, float v2, float h) {
    if (h < 0.0f) {
        h += 1.0f;
    }
    if (h > 1.0f) {
        h -= 1.0f;
    }

    if ((6.0f * h) < 1.0f) {
        return v1 + (v2 - v1) * 6.0f * h;
    }
    if ((2.0f * h ) < 1.0f) {
        return v2;
    }
    if ((3.0f * h) < 2.0f) {
        return v1 + (v2 - v1) * (( 2.0f / 3.0f) - h) * 6.0f;
    }

    return v1;
}

Color Color::from_rgba8(uint8_t* data) {
    Color c;
    c.r = ((float) data[0]) / 256.0f;
    c.g = ((float) data[1]) / 256.0f;
    c.b = ((float) data[2]) / 256.0f;
    c.a = ((float) data[3]) / 256.0f;
    return c;
}

Color ColorHSL::to_rgb() {
    Color rgb;
    rgb.a = a;
    if (s == 0) {
        rgb.r = l;
        rgb.g = l;
        rgb.b = l;
    } else {
        float v2;
        if (l < 0.5f) {
            v2 = l * (1.0f + s);
        } else {
            v2 = (l + s) - (s * l);
        }

        float v1 = 2 * l - v2;

        rgb.r = hue_to_rgb(v1, v2, h + (1.0f / 3.0f));
        rgb.g = hue_to_rgb(v1, v2, h);
        rgb.b = hue_to_rgb(v1, v2, h - (1.0f / 3.0f));
    }

    return rgb;
}
