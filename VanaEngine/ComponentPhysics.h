#pragma once
#include "pch.h"

class ComponentPhysics : public Component
{
public:
	ComponentPhysics(CollisionManager& manager, glm::vec2 size);
	~ComponentPhysics();
	void Init();
	void Update();
	void Shutdown();
	void HandleEvent();
private:
	Collider* collider;
};