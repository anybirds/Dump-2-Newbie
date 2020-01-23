#pragma once

#include <string>

namespace Engine {

	/*
	Resource

	Base class for all the resources such as Mateiral, Mesh, Model, Texture, etc.
	*/
	class Resource {
	private:
		std::string name;

	public:
		Resource(const char *name);
		virtual ~Resource();

		const std::string& GetName() const { return name; }
		Resource& SetName(const std::string &name) { this->name = name; return *this; }
	};
}