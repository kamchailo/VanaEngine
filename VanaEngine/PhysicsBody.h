#pragma once

class ComponentPhysics;

class PhysicsBody
{
public:
	PhysicsBody(int _mass, ComponentPhysics* _component, Collider* _collider);
	~PhysicsBody();
	void Integrate();
	void AddForce(glm::vec3 _force);
	void SetVelocity(glm::vec3 _velocity);
	void Dampen();
	void UpdateNodeTransform();
	Collider* GetCollider() const;
private:
	ComponentPhysics* physicsComponent;
	Collider* collider;
	float mass;
	float inverseMass;
	float friction;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 velocity;
	glm::vec3 angularVelocity;
	glm::vec3 acceleration;
	glm::vec3 force;

};