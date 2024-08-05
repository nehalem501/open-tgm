/* GeneratedTexture.cpp - GPU */

#include <math.h>
#include <canvas_ity.hpp>

#define CANVAS_ITY_IMPLEMENTATION
#include "GeneratedTexture.h"

void draw_block(double /*size*/, std::function<void(const uint8_t*)> /*callback*/) {
    /*cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, size, size);
    cairo_t* cr = cairo_create(surface);

    double color1 = 0.92;
    double color2 = 0.38;

    cairo_pattern_t* gradient = cairo_pattern_create_linear(0, size * 0.17, 0, size * 0.84);

    cairo_pattern_add_color_stop_rgba(gradient, 0, color1, color1, color1, 1);
    cairo_pattern_add_color_stop_rgba(gradient, 1, color2, color2, color2, 1);

    cairo_set_source_rgba(cr, 1, 0, 0, 1);
    cairo_rectangle(cr, 0, 0, size, size);
    cairo_fill(cr);

    double gradient_size = round(size / 8.0);
    double xy1 = gradient_size;
    double xy2 = size - (gradient_size * 2.0);

    cairo_rectangle(cr, xy1, xy1, xy2, xy2);
    cairo_set_source(cr, gradient);
    cairo_fill(cr);

    cairo_surface_flush(surface);

    unsigned char* data = cairo_image_surface_get_data(surface);
    callback(data);

    cairo_destroy(cr);
    cairo_surface_destroy(surface);*/
}
