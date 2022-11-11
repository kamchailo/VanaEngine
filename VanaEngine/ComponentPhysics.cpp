#include "pch.h"
#include "ComponentPhysics.h"

ComponentPhysics::ComponentPhysics(CollisionManager& _manager, glm::vec2 size)
{
	this->manager = &_manager;
	Collider* collider = this->manager->SpawnCollider(COLLIDER_AABB, size.x, size.y);
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

void ComponentPhysics::Update()
{
	//std::cout << "Update Phys Comp : " << collider->colliderID
	//	<< " position : " << collider->GetPosition().x
	//	<< ", " << collider->GetPosition().y
	//	<< ", " << collider->GetPosition().z
	//	<< std::endl;

	body->Integrate();

	//collider->SetPosition(owner->GetPosition());
	//collider->SetRotation(owner->GetRotation());


}

void ComponentPhysics::Shutdown()
{
}

void ComponentPhysics::HandleEvent()
{
}
