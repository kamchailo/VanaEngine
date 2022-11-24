#include "pch.h"
#include "ComponentPhysics.h"

ComponentPhysics::ComponentPhysics(CollisionManager& _manager, glm::vec2 size)
{
	this->manager = &_manager;
	Collider* collider = this->manager->SpawnCollider(COLLIDER_AABB, this, size.x, size.y);
	body = new PhysicsBody(1, this, collider);
	//this->collider = manager.SpawnCollider(COLLIDER_AABB, size.x, size.y);
	//std::cout << "Collider ID: " << collider->colliderID << std::endl;
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
		//EventCollisionMessage* msg = dynamic_cast<EventCollisionMessage*>(e->GetUserData());
		EventCollisionMessage* msg = reinterpret_cast<EventCollisionMessage*>(e->GetUserData());
		/*
		std::cout << "There is EventCollision between cID "
			<< msg->origin->colliderID
			<< " with ";
		for (int i = 0; i < msg->origin->GetCollideds().size(); ++i)
		{
			std::cout << " cID[" << msg->origin->GetCollideds()[i]->colliderID <<"] , ";
		}
		std::cout << " Total Collideds : " << msg->origin->GetCollideds().size();
		std::cout << std::endl;
		*/
	}
}
