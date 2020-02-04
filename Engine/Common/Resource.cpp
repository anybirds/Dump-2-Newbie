#include <Common/Project.hpp>
#include <Common/Resource.hpp>

using namespace std;
using namespace Engine;

namespace Engine {
    TYPE_DEF(Resource)

    TOJSON_BEGIN(Resource)
    TOJSON_END

    // hack used to initialize the resource only when loading Scene
    void from_json(const json &js, Resource *&res) {
        res->shouldLoad = Resource::sceneLoad;
        std::string name = js.get<std::string>(); res = Engine::Find<Resource>(name);
    }
    void from_json(const json &js, Resource &res) { }
}

bool Resource::sceneLoad;

Resource::Resource(const string &name, Type *type) : Object(name, type) {
    Project::resset.insert(this);
}

Resource::~Resource() {
    Project::resset.erase(this);
}
