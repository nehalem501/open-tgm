/* shaders.h - SDL2 */

#ifndef SHADERS_SDL2_H
#define SHADERS_SDL2_H

#include <GL/glew.h>

const GLchar *vertex_shader_source[] = {
    "#version 130\n"
    "in vec2 position; "
    "void main() { "
    "  gl_Position = vec4(position.x, position.y, 0, 1); "
    "}"
};

const GLchar *fragment_shader_source[] = {
    "#version 130\n"
    "out vec4 fragment; "
    "void main() { "
    "  fragment = vec4(1.0, 1.0, 1.0, 1.0); "
    "}"
};

#endif
