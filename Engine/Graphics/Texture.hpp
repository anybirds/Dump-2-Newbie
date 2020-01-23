#pragma once

#include <string>

#include <GL/glew.h>

#include <Core/Resource.hpp>

namespace Engine {

	/*
	Texture
	
	Represents a texture that has been created by loading images.
	*/
	class Texture final : public Resource {
	private:
		GLuint id;

	public:
		Texture(const char *name, const char *texture_path);
		~Texture();
		GLuint GetId() const { return id; }
	};
}
