/* shaders.h - SDL2 */

#ifndef SHADERS_SDL2_H
#define SHADERS_SDL2_H

#include <GL/glew.h>

const GLchar *vertex_shader_source[] = {
    "#version 150\n"
    "in vec3 position; "
    "/*in vec4 color_in;*/ "
    "out vec4 color_out; "
    "void main() { "
    "  /*color_out = color_in*/; "
    "  gl_Position = vec4(position.x, position.y, position.z, 1.0); "
    "}"
};

const GLchar *fragment_shader_source[] = {
    "#version 150\n"
    "/*in vec4 color_out;*/ "
    "out vec4 fragment; "
    "void main() { "
    "  /*fragment = color_out;*/ "
    "  fragment = vec4(1, 0, 0, 1); "
    "}"
};

#endif
