#pragma once

#include "../Physics/CollisionManager.h"
#include "../Physics/PhysicsBody.h"
#include "../Event/Event.h"

class ComponentPhysics : public Component
{
public:
	ComponentPhysics(CollisionManager& manager, glm::vec2 size, int selfLayer, int targetLayer);
	~ComponentPhysics();
	void Init();
	void Update(double _dt);
	void Shutdown();
	virtual void HandleEvent(Event* _event);
	PhysicsBody* body;
private:
	CollisionManager* manager;
};