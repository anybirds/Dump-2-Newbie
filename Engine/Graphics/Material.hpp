#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <unordered_map>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <Common/Resource.hpp>

#include <engine_global.hpp>

namespace Engine {
    class Shader;
    class Texture;
    class Renderer;

    class ENGINE_EXPORT Material final : public Resource {
    private:
        GLuint program;
        Texture *main_texture;

    public:
        Material(const char *name, const Shader *vert_shader, const Shader *frag_shader);
        ~Material();

        int GetInteger(const char *name) const;
        std::vector<int> GetIntegerArray(const char *name) const;
        float GetFloat(const char *name) const;
        std::vector<float> GetFloatArray(const char *name) const;
        glm::vec4 GetVector(const char *name) const;
        std::vector<glm::vec4> GetVectorArray(const char *name) const;
        glm::mat4 GetMatrix(const char *name) const;
        std::vector<glm::mat4> GetMatrixArray(const char *name) const;
        Texture* GetMainTexture() const { return main_texture; }

        void SetInteger(const char *name, int value);
        void SetIntegerArray(const char *name, const int *value, int length);
        void SetFloat(const char *name, float value);
        void SetFloatArray(const char *name, const float *value, int length);
        void SetVector(const char *name, const glm::vec4 &value);
        void SetVectorArray(const char *name, const glm::vec4 *value, int length);
        void SetMatrix(const char *name, const glm::mat4 &value);
        void SetMatrixArray(const char *name, const glm::mat4 *value, int length);
        void SetMainTexture(Texture *texture) { main_texture = texture; }

        void UseTextures();

        friend class Renderer;
    };
}

#endif
