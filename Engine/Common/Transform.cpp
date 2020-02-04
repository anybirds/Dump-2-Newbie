#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <Common/Transform.hpp>

using namespace std;
using namespace glm;
using namespace Engine;

namespace Engine {
    TYPE_DEF(Transform)
    SER_DEF(Transform, Component,
    MEMBER_SER | MEMBER_SHOW, glm::vec3, localPosition,
    MEMBER_SER | MEMBER_SHOW, glm::vec3, localEulerAngles,
    MEMBER_SER | MEMBER_SHOW, glm::vec3, localScale,
    MEMBER_SER, Transform *, parent,
    MEMBER_SER, std::vector<Transform *>, children
    )
}

Transform::Transform(const string &name, Type *type) : Component(name, type) {

}

Transform::~Transform() {

}

void Transform::PropagateUpdate() {
    if (!updated) {
        return;
    }
    updated = false;

    for (Transform *transform : children) {
        transform->PropagateUpdate();
    }
}

void Transform::OnInit() {
    localToWorldMatrix = GetLocalToWorldMatrix();
}

mat4 Transform::GetLocalToWorldMatrix() const {
    if (!updated) {
        updated = true;

        mat4 T = glm::translate(mat4(1.0f), localPosition);
        quat R = localRotation;
        mat4 S = glm::scale(mat4(1.0f), localScale);
        mat4 P = parent? parent->GetLocalToWorldMatrix() : mat4(1.0f);
        localToWorldMatrix = P * T * toMat4(R) * S;
    }
    return localToWorldMatrix;
}

mat4 Transform::GetWorldToLocalMatrix() const {
    return inverse(GetLocalToWorldMatrix());
}

vec3 Transform::GetPosition() const {
    return mat3(GetLocalToWorldMatrix()) * localPosition;
}

quat Transform::GetRotation() const {
    return toQuat(GetLocalToWorldMatrix() * toMat4(localRotation));
}

vec3 Transform::GetScale() const {
    return mat3(GetLocalToWorldMatrix()) * localScale;
}

void Transform::SetLocalPosition(const glm::vec3 &localPosition) {
    this->localPosition = localPosition;
    PropagateUpdate();
}

void Transform::SetLocalScale(const glm::vec3 &localScale) {
    this->localScale = localScale;
    PropagateUpdate();
}

void Transform::SetLocalEulerAngles(const glm::vec3 &localEulerAngles) {
    this->localEulerAngles = localEulerAngles;
    this->localRotation = toQuat(GetLocalToWorldMatrix() * eulerAngleZXY(radians(localEulerAngles.z), radians(localEulerAngles.x), radians(localEulerAngles.y)));
    PropagateUpdate();
}

void Transform::SetPosition(const glm::vec3 &position) {
    this->localPosition = mat3(GetWorldToLocalMatrix()) * position;
    PropagateUpdate();
}

void Transform::SetScale(const glm::vec3 &scale) {
    this->localScale = mat3(GetWorldToLocalMatrix()) * scale;
    PropagateUpdate();
}



