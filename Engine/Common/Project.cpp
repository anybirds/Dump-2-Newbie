#include <fstream>
#include <unordered_map>

#include <Common/Project.hpp>
#include <Common/Resource.hpp>
#include <Common/Scene.hpp>
#include <Common/Type.hpp>

using namespace std;
using namespace Engine;

string Project::path;

void Project::Clear() {
    unordered_map<Object *, Type *> objs(Object::objs);
    for (auto p : objs) {
        delete p.first;
    }
}

bool Project::Load(const string &path) {
    Project::path = path;

    // read json file
    ifstream pfs(path);
    if (pfs.fail()) {
        return false;
    }
    json js;
    pfs >> js;

    // pre-deserialization
    for (json::iterator i = js.begin(); i != js.end(); i++) {
        Type *type = Type::Find(i.key());
        for (json::iterator j = i.value().begin(); j != i.value().end(); j++) {
            type->Instantiate(j.key());
        }
    }

    // deserialization
    for (json::iterator i = js.begin(); i != js.end(); i++) {
        Type *type = Type::Find(i.key());
        for (json::iterator j = i.value().begin(); j != i.value().end(); j++) {
            type->Deserialize(j.value(), Find<Object>(j.key()));
        }
    }

    return true;
}

void Project::Save() {
    ofstream pfs(path);
    json js;

    for (Scene *scene : sceneset) {
        js["Scene"].push_back(*scene);
    }

    for (Resource *res : resset) {
        Type *type = GetType(res);
        type->Serialize(js[type->GetName()][res->GetName()], res);
    }

    pfs << js;
}
