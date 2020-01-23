#pragma once

#include <engine_global.hpp>

namespace Engine {

	class Object;

	/*
	Component
	
	Base class for components that comprise an Object.
	*/
    class ENGINE_EXPORT Component {
	private:
		Object *object;

	public:

		Component(Object *object);
		virtual ~Component();

		Engine::Object& GetObject() const { return *object; }
	};
}
