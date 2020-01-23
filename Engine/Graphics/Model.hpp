#pragma once

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Graphics/Mesh.hpp>

namespace Engine {

	class Model final {
	public:
		/* Import a model and create all meshes it has */
		static bool Import(const char *model_path);
	};
}
