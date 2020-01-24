#ifndef MODEL_H
#define MODEL

#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <Graphics/Mesh.hpp>

#include <engine_global.hpp>

namespace Engine {

    class ENGINE_EXPORT Model final {
	public:
		/* Import a model and create all meshes it has */
		static bool Import(const char *model_path);
	};
}

#endif
