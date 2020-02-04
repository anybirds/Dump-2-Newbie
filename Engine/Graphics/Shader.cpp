#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>

#include <Common/Debug.hpp>
#include <Common/Resource.hpp>
#include <Graphics/Shader.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace std;
using namespace Engine;

Shader::Shader(const char *name, GLenum type, const char *path)
    : Resource(name), type(type) {
    switch (type) {
    case GL_VERTEX_SHADER:
        shader = glCreateShader(GL_VERTEX_SHADER);
        break;
    case GL_FRAGMENT_SHADER:
        shader = glCreateShader(GL_FRAGMENT_SHADER);
        break;
    default:
        break;
    }

    if (!shader) {
#ifdef DEBUG
        cout << '[' << __FUNCTION__ << ']' << " failed to create a new shader" << endl;
#endif
        throw exception();
    }

    ifstream file(path);
    if (!file.is_open()) {
#ifdef DEBUG
        cout << '[' << __FUNCTION__ << ']' << " failed to find a shader: " << path << endl;
#endif
        glDeleteShader(shader);
        throw exception();
    }

    stringstream buf;
    buf << file.rdbuf();
    string source = buf.str();
    const char *source_char = source.c_str();
    glShaderSource(shader, 1, &source_char, NULL);

    glCompileShader(shader);
    GLint status = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
    if (status == GL_FALSE) {
#ifdef DEBUG
        cout << '[' << __FUNCTION__ << ']' << " failed to Compile a shader: " << path << endl;
#endif
        glDeleteShader(shader);
        throw exception();
    }
}

Shader::~Shader() {
    glDeleteShader(shader);
}
