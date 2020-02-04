#include <Common/Object.hpp>

using namespace std;
using namespace Engine;

namespace Engine {
    TYPE_DEF(Object)

    TOJSON_BEGIN(Object)
    TOJSON_END

    FROMJSON_BEGIN(Object)
    FROMJSON_END
}

unordered_map<Object *, Type *> Object::objs;
unordered_map<string, Object *> Object::objmap;

Object::Object(const string &name, Type *type) {
    objs.insert({this, type});
    objmap.insert({name, this});
}

Object::~Object() {
    // calling a virtual function in destructor does not invoke the derived class function
    OnDestroy();

    objs.erase(this);
    objmap.erase(name);
}
