#ifndef COMPONENT_H
#define COMPONENT_H

#include <Common/Object.hpp>

#include <engine_global.hpp>

namespace Engine {

    class GameObject;

    SER_DECL(Component)

    /*
    Base class for components that comprise a GameObject.
    */
    class ENGINE_EXPORT Component : public Object {
        TYPE_DECL(Component)

        PROPERTY_GET(GameObject *, GameObject, gameObject)

    public:
        Component(const std::string &name, Type *type = &Component::type);
        virtual ~Component();
    };
}

#endif
