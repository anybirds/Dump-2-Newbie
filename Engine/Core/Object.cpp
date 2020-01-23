#include <Core/Component.hpp>
#include <Core/Object.hpp>
#include <Core/World.hpp>

using namespace Engine;

Object::Object(const char *name, const Transform &transform) : name(name), transform(transform) {
	World::AddObject(*this);
}

Object::~Object() {
	for (auto item : component) {
		delete item.second;
	}

	World::RemoveObject(*this);
}