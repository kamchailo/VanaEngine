#include "pch.h"
#include "ComponentPhysics.h"

ComponentPhysics::ComponentPhysics(CollisionManager& manager, glm::vec2 size)
{
	this->collider = manager.SpawnCollider(COLLIDER_AABB, size.x, size.y);
	std::cout << "Collider ID: " << collider->colliderID << std::endl;
}

ComponentPhysics::~ComponentPhysics()
{

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

	collider->SetPosition(owner->GetPosition());
	collider->SetRotation(owner->GetRotation());
}

void ComponentPhysics::Shutdown()
{
}

void ComponentPhysics::HandleEvent()
{
}
