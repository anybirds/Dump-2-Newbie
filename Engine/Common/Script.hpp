#pragma once

#include <engine_global.hpp>

namespace Engine {
	
	/*
	Script
	
	Interface for user defined callback functions, such as Start and Update. 
	Multiple inheritance with Component is used to make a user defined script component.
	*/
    class ENGINE_EXPORT Script {
	public:
		Script();
		virtual ~Script();
		virtual void Start() = 0;
		virtual void Update() = 0;
	};
}
