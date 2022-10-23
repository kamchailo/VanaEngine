#pragma once
#include "pch.h"

class ComponentCollider : public Component
{
public:
	ComponentCollider();
	~ComponentCollider();
	void Init() = 0;
	void Update() = 0;
	void Shutdown() = 0;
	void HandleEvent() = 0;
private:

};