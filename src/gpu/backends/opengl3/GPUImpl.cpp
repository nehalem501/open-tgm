/* GPUImpl.h - OpenGL3 */

#include <stdlib.h>
#include <stdio.h>
#include <Global.h>
#include <Texture.h>
#include <GPU.h>
#include <GPUImpl.h>
#include "shaders.h"

int max_texture_size = 0;

static GLuint compile_shader(const GLchar *source[], const GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, source, NULL);
    glCompileShader(shader);

    GLint compile_error = GL_FALSE;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compile_error);
    if (compile_error != GL_TRUE) {
        int max = 0;
        int length = 0;

        printf("Could not compile shader:\n%s\n", source[0]);

        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &max);
        char *err_string = new char[max];
        glGetShaderInfoLog(shader, max, &length, err_string);
        if (length > 0)
            printf("%s\n", err_string);

        delete[] err_string;

        return 0;
    }

    return shader;
}

static bool link_program(GLuint program, GLuint v_shader, GLuint f_shader) {
    glAttachShader(program, v_shader);
    glAttachShader(program, f_shader);

    glLinkProgram(program);

    GLint link_status = GL_TRUE;
    glGetProgramiv(program, GL_LINK_STATUS, &link_status);
    if (link_status != GL_TRUE) {
        int max = 0;
        int length = 0;

        printf("Could not link program: ");

        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &max);
        char *err_string = new char[max];
        glGetProgramInfoLog(program, max, &length, err_string);
        if (length > 0)
            printf("%s\n", err_string);
        else
            printf("\n");

        delete[] err_string;

        return false;
    }

    return true;
}

static GLuint program_id = 0; // TODO
static GLint vertex_position = 0; // TODO
static GLuint VBO = 0; // TODO
static GLuint VAO = 0; // TODO

void init_gpu() {
    // Init GLEW
    glewExperimental = GL_TRUE;
    GLenum glew_error = glewInit();
    if (glew_error != GLEW_OK) {
        printf("Could not initialize GLEW: %s\n",
               glewGetErrorString(glew_error));
        exit(1);
    }

    program_id = glCreateProgram();

    GLuint vertex_shader = compile_shader(vertex_shader_source,
                                          GL_VERTEX_SHADER);
    GLuint fragment_shader = compile_shader(fragment_shader_source,
                                            GL_FRAGMENT_SHADER);
    if (vertex_shader == 0 || fragment_shader == 0) {
        printf("OpenGL: shader compilation error\n");
        exit(1);
    }

    if (!link_program(program_id, vertex_shader, fragment_shader)) {
        printf("OpenGL: shader program linking error\n");
        exit(1);
    }

    vertex_position = glGetAttribLocation(program_id, "position");

    // TODO
    //resize(screen.width, screen.height);

    glClearColor(0.0f, 0.0f, 0.5f, 1.0f);

    //VBO data
    GLfloat vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);
}

void graphics_clear() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void graphics_display() {
    //SDL_GL_SwapBuffers(); // TODO: remove SDL dependency

    glUseProgram(program_id);

    glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void resize(unsigned int /*width*/, unsigned int /*height*/) {
    /*screen.width =  width;
    screen.height = height;

    glViewport(0, 0, width, height);*/

    // TODO
}
