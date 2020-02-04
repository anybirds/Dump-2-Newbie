#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

#include <GL/glew.h>

#include <Common/Resource.hpp>

#include <engine_global.hpp>

namespace Engine {

	/*
	Texture
	
	Represents a texture that has been created by loading images.
	*/
    class ENGINE_EXPORT Texture final : public Resource {
	private:
		GLuint id;

	public:
		Texture(const char *name, const char *texture_path);
        ~Texture();

        friend class Material;
	};
}

#endif
