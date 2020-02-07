#include <Common/GameObject.hpp>
#include <Common/Time.hpp>
#include <Common/Transform.hpp>

#include <Scripts/RotateScript.hpp>

using namespace glm;
using namespace std;

TYPE_DEF(RotateScript)
SER_DEF(RotateScript, Component,
MEMBER_SER | MEMBER_SHOW, float, rate
)

RotateScript::RotateScript(const string &name, Type *type) : Component(name, type) {

}

void RotateScript::OnUpdate() {
    float dt = Time::DeltaTime();
    Transform *transform = GetGameObject()->GetTransform();
    transform->Rotate(vec3(0.0f, rate * dt, 0.0f));
}
