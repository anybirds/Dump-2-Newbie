#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <engine_global.hpp>

namespace Engine {	

	/*
	Transform

	Object's position, rotation, scale and hierarchical parent information.
	 */
    class ENGINE_EXPORT Transform final {
	private:
		glm::vec3 position;
		glm::mat4 rotation;
		glm::vec3 scale;
		const Transform *parent;

	public:
		struct Data {
			glm::vec3 position;
			glm::mat4 rotation;
			glm::vec3 scale;
			const Transform *parent;
		};

		Transform();
		Transform(const glm::vec3 &position, const glm::mat4 &rotation, const glm::vec3 &scale, const Transform *parent = nullptr);
		~Transform();

		glm::vec3 GetPosition() const { return position; }
		Transform& SetPosition(const glm::vec3 &position) { this->position = position; return *this; }
		glm::mat4 GetRotation() const { return rotation; }
		Transform& SetRotation(const glm::mat4 &rotation) { this->rotation = rotation; return *this; }
		glm::vec3 GetScale() const { return scale; }
		Transform& SetScale(const glm::vec3 &scale) { this->scale = scale; return *this; }

		/*
		Computes transform's 4*4 matrix representation. 
		 */
		glm::mat4 GetMatrix() const;
	};
}

#endif
