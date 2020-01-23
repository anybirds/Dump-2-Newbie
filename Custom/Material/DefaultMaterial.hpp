#pragma once

#include <Graphics/Material.hpp>
#include <Graphics/Texture.hpp>

class DefaultMaterial final : public Engine::Material {
private:
	Engine::Texture *texture;

public:
	DefaultMaterial(const char *name, const char *vert_path, const char *frag_path, Engine::Texture *texture);
	~DefaultMaterial();
	virtual void Uniform() const;
	const Engine::Texture& GetTexture() { return *texture; }
	DefaultMaterial& SetTexture(Engine::Texture &texture) { this->texture = &texture; return *this; }
};