#pragma once

#include "pch.h"

class Node;
class ColliderAABB;
class ColliderOOBB;
class CollisionManager;

enum ColliderType
{
	COLLIDER_AABB,
	COLLIDER_OOBB,
	COLLIDER_CIRCLE
};

// Abstract Class
class Collider
{
public:
	// Update to update parameter eg. move vertices to match GameObject
	virtual void Update() = 0;
	virtual void SetPosition(glm::vec3) = 0;
	virtual void SetRotation(glm::vec3) = 0;
	glm::vec3 GetPosition() const { return position; };
	glm::vec3 GetRotation() const { return rotation; };
	//Double Dispatch Pattern
	virtual bool Collide(Collider*) = 0;
	virtual bool Collide(ColliderAABB*) = 0;
	virtual bool Collide(ColliderOOBB*) = 0;
	//virtual bool Collide(ColliderCircle*) = 0;
	// @@ Figure out way to assign narrowCollider
	void GenerateNarrowCollider(CollisionManager& manager, ColliderType type)
	{
	};

	std::vector<glm::vec3>& GetVertices() { return vertices; };
	//virtual void CheckCollision(std::vector<Collider*> const* colliders) = 0;
	void AddCollided(Collider* collider) {
		collideds.push_back(collider);
	}
	void ResetCollided() {
		collideds.clear();
	};
	//void CreateNarrowAsOOBB(glm::vec3 minPoint, glm::vec3 maxPoint);
	//void CreateNarrowAsCircle();
	ColliderType type;
	Collider* narrowCollider;
	const unsigned int colliderID;
protected:
	Collider(unsigned int colliderID, ColliderType type) : colliderID(colliderID), type(type) {};
	glm::mat4 transform;
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	std::vector< glm::vec3> vertices;
	std::vector<Collider*> collideds;
	Node* owner;
private:
};