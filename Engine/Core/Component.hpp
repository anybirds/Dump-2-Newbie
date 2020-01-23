#pragma once

namespace Engine {

	class Object;

	/*
	Component
	
	Base class for components that comprise an Object.
	*/
	class Component {
	private:
		Object *object;

	public:

		Component(Object *object);
		virtual ~Component();

		Engine::Object& GetObject() const { return *object; }
	};
}