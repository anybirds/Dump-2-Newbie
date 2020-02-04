#include <Common/Object.hpp>
#include <Common/Type.hpp>

using namespace std;
using namespace Engine;

namespace glm {
    void to_json(json &js, const glm::vec3 &v) {
        js = json{v.x, v.y, v.z};
    }

    void to_json(json &js, const glm::vec4 &v) {
        js = json{v.x, v.y, v.z, v.w};
    }

    void to_json(json &js, const glm::mat3 &m) {
        js = json{
        m[0][0], m[0][1], m[0][2],
        m[1][0], m[1][1], m[1][2],
        m[2][0], m[2][1], m[2][2],
        };
    }

    void to_json(json &js, const glm::mat4 &m) {
        js = json{
        m[0][0], m[0][1], m[0][2], m[0][3],
        m[1][0], m[1][1], m[1][2], m[1][3],
        m[2][0], m[2][1], m[2][2], m[2][3],
        m[3][0], m[3][1], m[3][2], m[3][3]
        };
    }

    void from_json(const json &js, glm::vec3 &v) {
        v = vec3(js[0], js[1], js[2]);
    }

    void from_json(const json &js, glm::vec4 &v) {
        v = vec4(js[0], js[1], js[2], js[3]);
    }

    void from_json(const json &js, glm::mat3 &m) {
        m = mat3(
        js[0][0], js[0][1], js[0][2],
        js[1][0], js[1][1], js[1][2],
        js[2][0], js[2][1], js[2][2]
        );
    }

    void from_json(const json &js, glm::mat4 &m) {
        m = mat4(
        js[0][0], js[0][1], js[0][2], js[0][3],
        js[1][0], js[1][1], js[1][2], js[1][3],
        js[2][0], js[2][1], js[2][2], js[2][3],
        js[3][0], js[3][1], js[3][2], js[3][3]
        );
    }
}

unordered_map<string, Type *> Type::typemap;

Type::Type(const string &name, InstantiateFunction inst, SerializeFunction ser, DeserializeFunction deser)
    : name(name), inst(inst), ser(ser), deser(deser) {
    typemap.insert({name, this});
}

Type::~Type() {
    typemap.erase(name);
}

