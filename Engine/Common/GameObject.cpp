#include <Common/Component.hpp>
#include <Common/GameObject.hpp>
#include <Common/Scene.hpp>

using namespace std;
using namespace Engine;

namespace Engine {
    TYPE_DEF(GameObject)
    SER_DEF(GameObject, Object,
    MEMBER_SER, Transform *, transform,
    MEMBER_SER, GameObject::ComponentMap, components)
}

GameObject::GameObject(const string &name, Type *type) : Object(name, type) {
    Scene::curr->goset.insert(this);
}

GameObject::~GameObject() {
    Scene::curr->goset.erase(this);
}


