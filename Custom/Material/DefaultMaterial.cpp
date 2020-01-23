#include <Material/DefaultMaterial.hpp>
#include <Engine.hpp>

using namespace Engine;

DefaultMaterial::DefaultMaterial(const char *name, const char *vert_path, const char *frag_path, Engine::Texture *texture)
	: Material(name, vert_path, frag_path), texture(texture) {

}

void DefaultMaterial::Uniform() const {
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, texture->GetId());
}

DefaultMaterial::~DefaultMaterial() {
	Material::~Material();
	if (texture) {
		GLuint name = texture->GetId();
		glDeleteTextures(1, &name); // second argument must be a pointer of lvalue
	}
}