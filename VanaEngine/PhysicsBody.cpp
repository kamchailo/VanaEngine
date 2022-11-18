#include "pch.h"
#include "PhysicsBody.h"

PhysicsBody::PhysicsBody(int _mass, ComponentPhysics* _component, Collider* _collider)
	: physicsComponent(_component)
	, collider(_collider)
	, mass(_mass)
	, inverseMass(1.0 / _mass)
	, friction(0.0)
	, velocity(glm::vec3(0))
	, angularVelocity(glm::vec3(0))
	, acceleration(glm::vec3(0))
	, force(glm::vec3(0))
{
}

PhysicsBody::~PhysicsBody()
{

}

void PhysicsBody::Integrate(double _dt)
{
	position = physicsComponent->GetOwner()->GetPosition();
	rotation = physicsComponent->GetOwner()->GetRotation();

	acceleration = force * inverseMass;
	velocity += acceleration * glm::vec3(_dt);
	rotation += angularVelocity * glm::vec3(_dt);
	position += velocity * glm::vec3(_dt);

	// @@ Collision Resolution

	Dampen();
	UpdateNodeTransform();
}

void PhysicsBody::AddForce(glm::vec3 _force)
{
	force += _force;
}

void PhysicsBody::SetVelocity(glm::vec3 _velocity)
{
	velocity = _velocity;
	//std::cout << " velocity : " << velocity.x  << std::endl;
}

void PhysicsBody::Dampen()
{
	double length = glm::length(velocity);
	if (glm::length(velocity) > 0)
	{
		force = force * inverseMass;
		if (glm::length(acceleration) < 0.1)
		{
			force = glm::vec3(0.0);
			acceleration = glm::vec3(0.0);
		}
	}
}

void PhysicsBody::UpdateNodeTransform()
{
	physicsComponent->GetOwner()->SetPosition(position);
	physicsComponent->GetOwner()->SetRotation(rotation);

	collider->SetPosition(position);
	collider->SetRotation(rotation);
}

Collider* PhysicsBody::GetCollider() const
{
	return collider;
}
