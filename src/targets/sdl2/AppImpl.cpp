/* AppImpl.cpp - SDL2 */

#include <stdio.h>
#include <SDL.h>
#include <GL/glew.h>
#include <Global.h>
#include <Scene.h>
#include <App.h>
#include "../utils/timing.h"
#include "shaders.h"

GLuint program_id = 0;

GLuint compile_shader(const GLchar *source[], const GLenum type) {
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

bool link_program(GLuint program, GLuint v_shader, GLuint f_shader) {
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

void app(Scene& scene) {
    SDL_Window *window = NULL;
    SDL_GLContext context;
    int win_width = 320;
    int win_height = 240;
    //bool fullscreen = false; // TODO load config

    // Init SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Could not initialize SDL: %s\n", SDL_GetError());
        exit(1);
    }

    // We want OpenGL 3.0 with core profile
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,
                        SDL_GL_CONTEXT_PROFILE_CORE);

    // Create app window and associated OpenGL context
    window = SDL_CreateWindow("Open TGM", SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED, win_width, win_height,
                              SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
    if (window == NULL) {
        printf("Could not create window: %s\n", SDL_GetError());
        exit(1);
    }

    context = SDL_GL_CreateContext(window);
    if (!context) {
        printf("Could not create OpenGL context: %s\n", SDL_GetError());
        exit(1);
    }

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

    GLint vertex_position = glGetAttribLocation(program_id, "position");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);


    ///////////////////////////////

    GLuint gVBO = 0;
    GLuint gIBO = 0;

    //VBO data
	GLfloat vertexData[] =
	{
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		 0.5f,  0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	//IBO data
	GLuint indexData[] = { 0, 1, 2, 3 };

	//Create VBO
	glGenBuffers( 1, &gVBO );
    glBindBuffer( GL_ARRAY_BUFFER, gVBO );
	glBufferData( GL_ARRAY_BUFFER, 3 * 4 * sizeof(GLfloat), vertexData, GL_STATIC_DRAW );

	//Create IBO
	glGenBuffers( 1, &gIBO );
	glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
    glBufferData( GL_ELEMENT_ARRAY_BUFFER, 4 * sizeof(GLuint), indexData, GL_STATIC_DRAW );

    //////////////////////////////

    #ifdef DEBUG
    bool frame_by_frame = false;
    bool do_frame = false;
    #endif

    bool quit = false;
    SDL_Event event;

    while(!quit) {
        //while() { TODO timing code
            while (SDL_PollEvent(&event) != 0) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                }

                if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                    switch (event.key.keysym.sym) {
                        case SDL_SCANCODE_ESCAPE:
                            quit = true;
                            break;

                        #ifdef DEBUG
                        case SDL_SCANCODE_P:
                            frame_by_frame = !frame_by_frame;
                            break;

                        case SDL_SCANCODE_N:
                            do_frame = true;
                            break;
                        #endif

                        case SDL_SCANCODE_F11:
                            // TODO fullscreen
                            break;

                        default:
                            break;
                    }
                }

                if (event.type == SDL_WINDOWEVENT) {
                    switch (event.window.event) {
                        case SDL_WINDOWEVENT_RESIZED:
                            // TODO resize
                            break;
                    }
                }
            }

            #ifdef DEBUG
            if (frame_by_frame) {
                if (!do_frame) {
                    continue;
                } else {
                    do_frame = false;
                }
            }
            #endif

            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram( program_id );

		    //Enable vertex position
		    glEnableVertexAttribArray(vertex_position);

		    //Set vertex data
		    glBindBuffer( GL_ARRAY_BUFFER, gVBO );
		    glVertexAttribPointer( vertex_position, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), NULL );

		    //Set index data and render
		    glBindBuffer( GL_ELEMENT_ARRAY_BUFFER, gIBO );
		    glDrawElements( GL_TRIANGLE_FAN, 4, GL_UNSIGNED_INT, NULL );

		    //Disable vertex position
		    glDisableVertexAttribArray( vertex_position );

		    //Unbind program
		    glUseProgram( NULL );

            // TODO
            scene.update();
            scene.draw();

            SDL_GL_SwapWindow(window);
        //}

        sleep_usecs(1000); // Sleep for 1 msec
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
}
