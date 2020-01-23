#include <glm/gtc/matrix_transform.hpp>

#include <Core/Debug.hpp>
#include <Core/Transform.hpp>

#ifdef DEBUG_CORE
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

Transform::Transform() {

}

Transform::Transform(const glm::vec3 &position, const glm::mat4 &rotation, const glm::vec3 &scale, const Transform *parent)
	: position(position), rotation(rotation), scale(scale), parent(parent) {

}

Transform::~Transform() {

}

mat4 Transform::GetMatrix() const {
	mat4 T = glm::translate(mat4(1.0f), position);
	mat4 R = rotation;
	mat4 S = glm::scale(mat4(1.0f), scale);
	
	mat4 P = parent? parent->GetMatrix() : mat4(1.0f);
	return P * T * R * S;
}