#include <Script/RotateScript.hpp>
#include <Engine.hpp>

using namespace glm;
using namespace Engine;

RotateScript::RotateScript(Object *object, float rate) 
	: Component(object), Script(),
	rate(rate) {

}

RotateScript::~RotateScript() {

}

void RotateScript::Start() {

}

void RotateScript::Update() {
	Transform &transform = GetObject().GetTransform();
	transform.SetRotation(rotate(transform.GetRotation(), radians(rate * Time::DeltaTime()), vec3(0.0f, 1.0f, 0.0f)));
}