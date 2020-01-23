#pragma once

#include <glm/glm.hpp>

#include <Common/Component.hpp>

#include <engine_global.hpp>

namespace Engine {

	/*
	Camera Component

	Featured by its normalization matrix. 
	Specify camera properties by directly manipulating the normalization matrix.
	glm::perspective, glm::otrho can be used.
	 */
    class ENGINE_EXPORT Camera final : public Component {
	private:
		static const Camera *current;

	public:
		static const Camera* GetCurrentCamera() { return current; }
		static void SetCurrentCamera(const Camera &current) { Camera::current = &current; }

	private:
		glm::mat4 normalization;

	public:
		Camera(Object *object, const glm::mat4 &normalization = glm::mat4(1.0f));
		~Camera();
		
		glm::mat4 GetNormalization() const { return normalization; }
		Camera& SetNormalization(const glm::mat4 &normalization) { this->normalization = normalization; return *this; }
	};
}
