/* OpenGL1Dispatch.h - SDL2 */

#ifndef OPENGL1DISPATCH_SDL2_H
#define OPENGL1DISPATCH_SDL2_H

// We need this for modern macOS
#define GL_SILENCE_DEPRECATION

#include <SDL_opengl.h>



#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
//#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
//#include <GL/freeglut.h>
#endif


#endif // OPENGL1DISPATCH_SDL2_H
