#include <glm/gtx/transform.hpp>

#include <Common/Scene.hpp>
#include <Graphics/Camera.hpp>

using namespace glm;
using namespace Engine;

namespace Engine {
    TYPE_DEF(Camera)
    SER_DEF(Camera, Component,
    MEMBER_SER | MEMBER_SHOW, bool, orthographic,
    MEMBER_SER | MEMBER_SHOW, float, fovy,
    MEMBER_SER | MEMBER_SHOW, float, width,
    MEMBER_SER | MEMBER_SHOW, float, height,
    MEMBER_SER | MEMBER_SHOW, float, near,
    MEMBER_SER | MEMBER_SHOW, float, far,
    MEMBER_SER | MEMBER_SHOW, float, left,
    MEMBER_SER | MEMBER_SHOW, float, right,
    MEMBER_SER | MEMBER_SHOW, float, bottom,
    MEMBER_SER | MEMBER_SHOW, float, top
    )
}

Camera *Camera::GetMainCamera() {
    return Find<SceneSetting>("RenderSetting")->GetMainCamera();
}

void Camera::SetMainCamera(Camera *camera) {
    Find<SceneSetting>("RenderSetting")->SetMainCamera(camera);
}

Camera::Camera(const std::string &name, Type *type) : Component(name, type) {

}

Camera::~Camera() {

}

void Camera::ComputeNormalization() {
    if (orthographic) {
        normalization = perspective(fovy, width / height, near, far);
    } else {
        normalization = ortho(left, right, bottom, top, near, far);
    }
}

void Camera::OnInit() {
    ComputeNormalization();
}

void Camera::SetFovy(float fovy) {
    this->fovy = fovy;
    ComputeNormalization();
}
void Camera::SetWidth(float width) {
    this->width = width;
    ComputeNormalization();
}

void Camera::SetNear(float near) {
    this->near = near;
    ComputeNormalization();
}

void Camera::SetFar(float far) {
    this->far = far;
    ComputeNormalization();
}

void Camera::SetLeft(float left) {
    this->left = left;
    ComputeNormalization();
}

void Camera::SetRight(float right) {
    this->right = right;
    ComputeNormalization();
}
void Camera::SetTop(float top) {
    this->top = top;
    ComputeNormalization();
}

void Camera::SetBottom(float bottom) {
    this->bottom = bottom;
    ComputeNormalization();
}

void Camera::Render() {

}

