#include <GL/glew.h>

#include <Common/Object.hpp>
#include <Common/Script.hpp>
#include <Common/World.hpp>
#include <Graphics/Renderer.hpp>

using namespace std;
using namespace Engine;

World World::world;

void World::AddObject(Object &object) {
	world.object.insert({ object.GetName(), &object });
}

void World::RemoveObject(Object &object) {
	world.object.erase(object.GetName());
}

Object* World::FindObject(const string &name) {
	auto it = world.object.find(name);
	if (it == world.object.end()) {
		return nullptr;
	}
	return it->second;
}

void World::Start() {
	auto it = world.event_listener.find(typeid(Script).hash_code());
	if (it == world.event_listener.end()) {
		return;
	}
	for (auto item : it->second) {
		Script *script = (Script*)item;
		script->Start();
	}
}

void World::Update() {
	auto it = world.event_listener.find(typeid(Script).hash_code());
	if (it == world.event_listener.end()) {
		return;
	}
	for (auto item : it->second) {
		Script *script = (Script*)item;
		script->Update();
	}
}

void World::Render() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	auto it = world.event_listener.find(typeid(Renderer).hash_code());
	if (it == world.event_listener.end()) {
		return;
	}
	for (auto item : it->second) {
		Renderer *renderer = (Renderer*)item;
		renderer->Render();
	}
}

World::World() {

}

World::~World() {
	for (auto item : object) {
		delete item.second;
	}
}
