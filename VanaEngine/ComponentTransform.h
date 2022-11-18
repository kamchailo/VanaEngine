#pragma once
#include "pch.h"

class ComponentTransform : public Component
{
public:
	ComponentTransform();
	void Init();
	void Update(double _dt);
	void Shutdown();
	virtual void HandleEvent(Event* _event);
};