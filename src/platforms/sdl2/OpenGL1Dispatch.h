/* OpenGL1Dispatch.h - SDL2 */

#ifndef OPENGL1DISPATCH_SDL2_H
#define OPENGL1DISPATCH_SDL2_H

#ifdef __APPLE__
// We need this for modern macOS
#define GL_SILENCE_DEPRECATION
#endif

// TODO
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
