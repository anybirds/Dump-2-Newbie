#ifndef ROTATE_SCRIPT_H
#define ROTATE_SCRIPT_H

#include <Common/Component.hpp>

#include <custom_global.hpp>

using namespace Engine;

SER_DECL(RotateScript)

class CUSTOM_EXPORT RotateScript : public Component {
    TYPE_DECL(RotateScript)

    PROPERTY(float, Rate, rate)

public:
    RotateScript(const std::string &name, Type *type = RotateScript::type);

	virtual void Start();
	virtual void Update();
};

#endif
