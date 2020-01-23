#include <Common/Script.hpp>
#include <Common/World.hpp>

using namespace Engine;

Script::Script() {
	World::AddEventListener(*this);
}

Script::~Script() {
	World::RemoveEventListener(*this);
}
