#ifndef SCENE_H
#define SCENE_H

#include <unordered_set>

#include <Common/Object.hpp>

#include <engine_global.hpp>

namespace Engine {

    class GameObject;
    class Component;
    class Camera;

    SER_DECL(SceneSetting)

    class ENGINE_EXPORT SceneSetting final : public Object {
        TYPE_DECL(SceneSetting)

        PROPERTY(Camera *, MainCamera, mainCamera)

    public:
        SceneSetting(const std::string &name, Type *type = &SceneSetting::type);
        virtual ~SceneSetting();
    };

    SER_DECL(Scene)

    /*
    Tracks objects and components that comprise the scene.
    */
    class ENGINE_EXPORT Scene final : public Object {
        TYPE_DECL(Scene)

        PROPERTY(std::string, Path, path)

    private:
        static Scene *curr;

    public:
        static void Clear();
        static bool Load(const std::string &name);
        static void Save();

    private:
        std::unordered_set<SceneSetting *> settingset;
        std::unordered_set<GameObject *> goset;
        std::unordered_set<Component *> compset;

    public:
        Scene(const std::string &name, Type *type = &Scene::type);
        virtual ~Scene();

        friend class SceneSetting;
        friend class GameObject;
        friend class Component;
    };
}

#endif