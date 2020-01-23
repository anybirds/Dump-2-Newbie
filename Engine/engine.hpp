#ifndef ENGINE_H
#define ENGINE_H

#include <GL/glew.h>

#include "engine_global.hpp"

class ENGINE_EXPORT Engine
{
private:
    static float tri[9];
    static GLuint vao;
    static GLuint vbo;
    static GLuint program;

public:
    static void prepareTriangle();
    static void drawTriangle();

public:
    Engine();
};

#endif // ENGINE_H
