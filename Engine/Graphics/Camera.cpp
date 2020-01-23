#include <Common/Debug.hpp>
#include <Graphics/Camera.hpp>

#ifdef DEBUG_GRAPHICS
#define DEBUG
#endif

using namespace glm;
using namespace Engine;

const Camera *Camera::current;

Camera::Camera(Object *object, const mat4 &normalization) : Component(object), normalization(normalization) {
	
}

Camera::~Camera() {

}
