#pragma once

#include <Core/Component.hpp>
#include <Core/Script.hpp>

class RotateScript : public Engine::Component, public Engine::Script {
private:
	float rate;

public:
	RotateScript(Engine::Object *object, float rate = 0.0f);
	virtual ~RotateScript();
	virtual void Start();
	virtual void Update();

	float GetRate() { return rate; }
	RotateScript& SetRate(float rate) { this->rate = rate; return *this; }
};