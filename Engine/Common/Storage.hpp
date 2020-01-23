#pragma once

#include <string>
#include <typeinfo>
#include <unordered_map>

#include <engine_global.hpp>

namespace Engine {

	class Resource;

	/*
	Storage

	Has mappings to find all the resources currently loaded to the game.
	*/
    class ENGINE_EXPORT Storage final {
	private:
		static Storage storage;

		template <typename ResourceType>
		static void AddResource(ResourceType &resource);

	public:
		template <typename ResourceType>
		static ResourceType* FindResource(const char *name);
		template <typename ResourceType>
		static void RemoveResource(ResourceType &name);

	private:
		std::unordered_map<std::string, Resource*> resource;

		Storage();

	public:
		Storage(const Storage&) = delete;
		Storage(Storage&&) = delete;
		Storage& operator=(const Storage &) = delete;
		Storage& operator=(Storage&&) = delete;
		~Storage();

		friend class Resource;
	};

	template <typename ResourceType>
	static void Storage::AddResource(ResourceType &resource) {
		storage.resource.emplace(resource.GetName(), &resource);
	}
	
	template <typename ResourceType>
	static void Storage::RemoveResource(ResourceType &resource) {
		storage.resource.erase(resource.GetName());
	}

	template <typename ResourceType>
	static ResourceType* Storage::FindResource(const char *name) {
		auto it = storage.resource.find(name);
		if (it == storage.resource.end()) {
			return nullptr;
		}
		return dynamic_cast<ResourceType*>(it->second);
	}
}
