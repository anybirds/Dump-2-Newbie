#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <Common/Resource.hpp>

#include <engine_global.hpp>

namespace Engine {
    class ENGINE_EXPORT Shader final : public Resource {
    private:
        GLenum type;
        GLuint shader;

    public:
        Shader(const char *name, GLenum type, const char *path);
        ~Shader();

        friend class Material;
    };
}

#endif
