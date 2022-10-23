#pragma once

#include "pch.h"

class ColliderOOBB;

class ColliderAABB : public Collider
{
public:
	// Constructor
	ColliderAABB(unsigned int id, glm::vec3 min, glm::vec3 max) : Collider(id, COLLIDER_AABB)
		, minPoint(min), maxPoint(max)
	{
		transform = glm::mat4(1);
		vertices.push_back(glm::vec3(min.x, max.y, 0.0)); // Top Left
		vertices.push_back(glm::vec3(max.x, max.y, 0.0)); // Top Right
		vertices.push_back(glm::vec3(max.x, min.y, 0.0));  // Bottom Right
		vertices.push_back(glm::vec3(min.x, min.y, 0.0));  // Bottom Left
	};
	// Override
	void Update();
	void SetPosition(glm::vec3);
	void SetRotation(glm::vec3);
	bool Collide(Collider*);
	bool Collide(ColliderAABB*);
	bool Collide(ColliderOOBB*);
	// GenerateNarrow
	//void GenerateNarrowCollider(CollisionManager& manager, ColliderType type);
	// Get
	glm::vec3 GetMinPoint() const;
	glm::vec3 GetMaxPoint() const;
private:
	glm::vec3 minPoint;
	glm::vec3 maxPoint;
	//float vertices[12];

};