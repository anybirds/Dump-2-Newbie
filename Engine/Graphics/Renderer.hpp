#pragma once

#include <Common/Component.hpp>

#include <engine_global.hpp>

namespace Engine {

	class Material;
	class Mesh;

	/*
	Renderer Component

	Responsible for rendering objects that have Mesh and Material.
	*/
    class ENGINE_EXPORT Renderer final : public Component {
	private:
		Mesh *mesh;
		Material *material;

	public:
		Renderer(Object *object, Mesh *mesh = nullptr, Material *material = nullptr);
		~Renderer();

		const Engine::Mesh& GetMesh() const { return *mesh; }
		Renderer& SetMesh(Engine::Mesh &mesh) { this->mesh = &mesh; return *this; }
		const Engine::Material& GetMaterial() const { return *material; }
		Renderer& SetMaterial(Engine::Material &material) { this->material = &material; return *this; }

		void Render();
	};
}
