#include "pch.h"
#include "ComponentPhysics.h"

#include "Physics/CollisionManager.h"
#include "Physics/Collider.h"
#include "Physics/PhysicsBody.h"

#include "Event/Event.h"
#include "Event/EventCollision.h"

ComponentPhysics::ComponentPhysics(CollisionManager& _manager, glm::vec2 size, int selfLayer, int targetLayer)
{
	this->manager = &_manager;
	Collider* collider = this->manager->SpawnColliderInLayer(selfLayer, targetLayer, COLLIDER_AABB, this, size.x, size.y);
	body = new PhysicsBody(1, this, collider);
}

ComponentPhysics::~ComponentPhysics()
{
	this->manager->DeleteCollider(body->GetCollider());
	delete body;
}

void ComponentPhysics::Init()
{
}

void ComponentPhysics::Update(double _dt)
{
	body->Integrate(_dt);
}

void ComponentPhysics::Shutdown()
{
}

void ComponentPhysics::HandleEvent(Event* _event)
{
	EventCollision* e = dynamic_cast<EventCollision*>(_event);
	if (e)
	{
		EventCollisionMessage* msg = reinterpret_cast<EventCollisionMessage*>(e->GetUserData());
	}
}