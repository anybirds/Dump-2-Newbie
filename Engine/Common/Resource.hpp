#ifndef RESOURCE_H
#define RESOURCE_H

#include <Common/Object.hpp>

#include <engine_global.hpp>

namespace Engine {

    SER_DECL(Resource)

    /*
    Base class for all the resources like Model, Mesh, Material, Shader, Texture and etc.
    */
    class ENGINE_EXPORT Resource : public Object {
        TYPE_DECL(Resource)

    private:
        static bool sceneLoad;

    private:
        bool loaded;
        bool shouldLoad;

    public:
        Resource(const std::string &name, Type *type = &Resource::type);
        virtual ~Resource();

        friend class Scene;
        friend void from_json(const json &, Resource *&);
    };
}
#endif
