#pragma once

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*
DEBUG macros enable compile-time choice of logging messages.
Per-file debugging can be done by turning on/off #define DEBUG.
Per-module debugging can be done by turning on/off #define DEBUG_[MODULE].

Example

#ifdef DEBUG_APPLICATION
#define DEBUG
#endif
...
#ifdef DEBUG
// log messages
#endif
*/

#define DEBUG_APPLICATION
#define DEBUG_CORE
#define DEBUG_GRAPHICS
#define DEBUG_INTERACTION
#define DEBUG_PHYSICS

using namespace std;

namespace Engine {
	/*
	Debug

	Provides a set of useful static functions for debugging.

	TODO
	Make Log(string) function that prints out a string message. 
	This is required to remove dependency against iostream.
	 */
	class Debug {
	public:
		/*
		Callback function that leaves an error message to the console window. 
		Gets called when OpenGL related functions fail. 
		 */
		static void APIENTRY GraphicsErrorLog(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);
	};
}