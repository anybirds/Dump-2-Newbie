#pragma once

#include <Common/Component.hpp>
#include <Common/Script.hpp>

#include <custom_global.hpp>

class CUSTOM_EXPORT RotateScript : public Engine::Component, public Engine::Script {
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
