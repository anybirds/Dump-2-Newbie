#pragma once

#include <exception>
#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

#include <Core/Resource.hpp>

namespace Engine {

	class ShaderCreationException final : public std::exception {
	public:
		const char *what() const noexcept {
			return "[ShaderCreationException] Failed to create a new shader.";
		}
	};

	class ShaderNotFoundException final : public std::exception {
	private:
		std::string msg;
	public:
		ShaderNotFoundException(const char *file_name) : msg("[ShaderNotFoundException] Failed to find a shader: ") {
			msg += file_name;
		}

		const char *what() const noexcept {
			return msg.c_str();
		}
	};

	class ShaderCompilationException : public std::exception {
	private:
		std::string msg;
	public:
		ShaderCompilationException(GLuint shader) : msg("[ShaderCompilationException] Failed to Compile a shader:\n") {
			GLint len;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
			GLchar *log = new GLchar[len + 1];
			glGetShaderInfoLog(shader, len, NULL, log);

			msg += log;

			delete[] log;
		}

		const char *what() const noexcept {
			return msg.c_str();
		}
	};

	/*
	Material

	Abstract class that defines how the objects are being drawn. 
	Automatically compiles given shaders and attach it to a program object, which gets linked right after.
	Inherit this class to create a new material with additional properties.
	 */
	class Material : public Resource {
	private:
		GLuint program;

		GLuint CompileShader(const char *path, GLenum type);
	public:
		Material(const char *name, const char *vert_path, const char *frag_path);
		virtual ~Material();
		virtual void Uniform() const = 0;

		friend class Renderer;
	};
}