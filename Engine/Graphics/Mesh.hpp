#pragma once

#include <GL/glew.h>

#include <Core/Resource.hpp>

namespace Engine {

	/*
	Mesh

	Represents a wireframe that exists in the object space. 
	Users must define a MeshDetail object and pass it as an argument in order to create a Mesh.
	Mesh object can consist points in 2D, 3D or whatever dimensional space, 
	can have multiple attributes for each vertex and can represent indexed wireframe. 
	*/
	class Mesh final : public Resource {
	private:
		unsigned vcnt;
		unsigned icnt;

		GLuint vao;
		GLuint vbo;
		GLuint ebo;
		
	public:

		/* acquires resources(VAO, VBO, EBO) needed to generate a mesh for a model */
		Mesh(const char *name, const float *vert, unsigned vcnt, const unsigned *attrib, unsigned acnt, const unsigned *idx = nullptr, unsigned icnt = 0);
		Mesh(const char *name, const char *model_path, unsigned midx = 0);
		~Mesh();

		friend class Renderer;
	};
}