#include <Common/Component.hpp>
#include <Common/Object.hpp>
#include <Common/World.hpp>

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
