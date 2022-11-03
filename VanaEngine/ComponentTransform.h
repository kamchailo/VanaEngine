#pragma once
#include "pch.h"

class ComponentTransform : public Component
{
public:
	ComponentTransform();
	void Init();
	void Update();
	void Shutdown();
	void HandleEvent();
};