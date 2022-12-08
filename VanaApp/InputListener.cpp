#include "InputListener.h"

void InputListener::Init()
{
}

void InputListener::Update(double _dt)
{
	if (Input::GetInstance()->IsPressed(action))
	{
		callback();
	}
}
