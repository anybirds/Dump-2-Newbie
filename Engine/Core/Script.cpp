#include <Core/Script.hpp>
#include <Core/World.hpp>

using namespace Engine;

Script::Script() {
	World::AddEventListener(*this);
}

Script::~Script() {
	World::RemoveEventListener(*this);
}