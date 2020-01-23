#include <unordered_map>
#include <set>
#include <string>
#include <typeinfo>

#include <Core/Object.hpp>

namespace Engine {

	class Renderer;
	class Script;

	/*
	World

	Has every objects instantiated
	Trigger events for components like Script and Renderer.
	*/
	class World final {
	private:
		static World world;

		static void AddObject(Object &object);
		static void RemoveObject(Object &object);

	public:
		static Object* FindObject(const std::string &name);

		template <typename EventListenerType>
		static void AddEventListener(EventListenerType &event_listener);
		template <typename EventListenerType>
		static void RemoveEventListener(EventListenerType &event_listener);

		static void Start();
		static void Update();
		static void Render();

	private:
		std::unordered_map<std::string, Object*> object;
		std::unordered_map<size_t, std::set<void*>> event_listener;

		World();
		
	public:
		World(const World&) = delete;
		World(World&&) = delete;
		World& operator=(const World&) = delete;
		World& operator=(World&&) = delete;
		~World();

		friend class Object;
	};

	template <typename EventListenerType>
	static void World::AddEventListener(EventListenerType &event_listener) {
		size_t key = typeid(EventListenerType).hash_code();
		auto it = world.event_listener.find(key);
		if (it == world.event_listener.end()) {
			it = world.event_listener.insert({ key, std::set<void*>() }).first;
		}
		it->second.insert((void*)&event_listener);
	}

	template <typename EventListenerType>
	static void World::RemoveEventListener(EventListenerType &event_listener) {
		size_t key = typeid(EventListenerType).hash_code();
		auto it = world.event_listener.find(key);
		if (it == world.event_listener.end()) {
			return;
		}
		it->second.erase((void*)&event_listener);
	}
}