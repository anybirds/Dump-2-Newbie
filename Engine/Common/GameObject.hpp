#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <string>
#include <typeinfo>
#include <unordered_map>

#include <Common/Object.hpp>
#include <Common/Transform.hpp>

#include <engine_global.hpp>

namespace Engine {

    class Component;

    SER_DECL(GameObject)

    /*
    An atraction of a gameobject in the scene.
    Has components that can describe the gameobject behavior.
    */
    class ENGINE_EXPORT GameObject final : public Object {
        TYPE_DECL(GameObject)

    public:
        typedef std::unordered_map<std::string, Component *> ComponentMap;

        PROPERTY(Transform *, Transform, transform)
        ComponentMap components;

    public:
        GameObject(const std::string &name, Type *type = &GameObject::type);
        virtual ~GameObject();

        template <typename T>
        T *GetComponent() const;
        template <typename T>
        T *AddComponent();
    };

    template <typename T>
    T *GameObject::GetComponent() const {

    }

    template <typename T>
    T *GameObject::AddComponent() {

    }
}
#endif
