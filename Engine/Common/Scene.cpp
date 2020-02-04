#include <fstream>
#include <iostream>

#include <GL/glew.h>

#include <nlohmann/json.hpp>

#include <Graphics/Camera.hpp>
#include <Common/Component.hpp>
#include <Common/GameObject.hpp>
#include <Common/Project.hpp>
#include <Common/Resource.hpp>
#include <Common/Scene.hpp>

using namespace std;
using json = nlohmann::json;
using namespace Engine;

namespace Engine {
    TYPE_DEF(SceneSetting)
    SER_DEF(SceneSetting, Object,
    MEMBER_SER | MEMBER_SHOW, Camera *, mainCamera
    )

    TYPE_DEF(Scene)
    SER_DEF(Scene, Object,
    MEMBER_SER | MEMBER_SHOW, std::string, path
    )
}

SceneSetting::SceneSetting(const std::string &name, Type *type) : Object(name, type) {
    Scene::curr->settingset.insert(this);
}

SceneSetting::~SceneSetting() {
    Scene::curr->settingset.erase(this);
}

Scene::Scene(const std::string &name, Type *type) : Object(name, type) {
    // glew init
    GLenum glew_error = glewInit();
    if (glew_error != GLEW_OK) {
        // Initializing GLEW failed
        cout << '[' << __FUNCTION__ << ']' << " message: " << glewGetErrorString(glew_error) << '\n';
        exit(1);
    }

    // render settings
    glEnable(GL_DEPTH_TEST);

    Project::sceneset.insert(this);
}

Scene::~Scene() {
    Project::sceneset.erase(this);
}

void Scene::Clear() {
    if (!IsValid(curr)) {
        return;
    }

    unordered_set<SceneSetting *> settingset(curr->settingset);
    unordered_set<GameObject *> goset(curr->goset);
    unordered_set<Component *> compset(curr->compset);

    for (SceneSetting *setting : settingset) {
        delete setting;
    }
    for (GameObject *go : goset) {
        delete go;
    }
    for (Component *comp : compset) {
        delete comp;
    }
    curr = nullptr;
}

bool Scene::Load(const string &name) {
    Scene *scene = Find<Scene>(name);
    if (!IsValid(scene)) {
        return false;
    }

    // read json file
    ifstream sfs(scene->GetPath());
    if (sfs.fail()) {
        return false;
    }
    json js;
    sfs >> js;

    // pre-deserialization
    for (json::iterator i = js.begin(); i != js.end(); i++) {
        Type *type = Type::Find(i.key());
        for (json::iterator j = i.value().begin(); j != i.value().end(); j++) {
            type->Instantiate(j.key());
        }
    }

    // deserialization
    Resource::sceneLoad = true;
    for (json::iterator i = js.begin(); i != js.end(); i++) {
        Type *type = Type::Find(i.key());
        for (json::iterator j = i.value().begin(); j != i.value().begin(); j++) {
            type->Deserialize(j.value(), Find<Object>(j.key()));
        }
    }
    Resource::sceneLoad = false;

    // post-deserialization
    try {
        for (Resource *res : Project::resset) {
            if (res->loaded && !res->shouldLoad) {
                res->OnInit();
            }
            if (!res->loaded && res->shouldLoad) {
                res->OnDestroy();
            }
        }
        for (Component *comp : scene->compset) {
            comp->OnInit();
        }
        for (GameObject *go : scene->goset) {
            go->OnInit();
        }
        for (SceneSetting *setting : scene->settingset) {
            setting->OnInit();
        }
    } catch(...) {
        return false;
    }
    return true;
}

void Scene::Save() {

}
