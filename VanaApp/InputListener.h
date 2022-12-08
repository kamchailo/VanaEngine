#pragma once

#include <VanaEngine.h>

typedef void(*callbackFunction)();

class InputListener : public Vana::Node
{
public:
	InputListener(InputAction _action, callbackFunction _func) : action(_action), callback(_func) {};
	~InputListener() {};
	void Init() override;
	void Update(double _dt) override;
	InputAction action;
	callbackFunction callback;
};