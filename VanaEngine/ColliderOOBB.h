#pragma once

#include "pch.h"

class ColliderOOBB : public Collider
{
public:
	// Constructor
	// @@ need to change param to vertices to support polygon
	ColliderOOBB(unsigned int id, glm::vec3 min, glm::vec3 max) : Collider(id, COLLIDER_OOBB)
	{
		transform = glm::mat4(1);
		vertices.push_back(glm::vec3(min.x, max.y, 0.0)); // Top Left
		vertices.push_back(glm::vec3(max.x, max.y, 0.0)); // Top Right
		vertices.push_back(glm::vec3(max.x, min.y, 0.0));  // Bottom Right
		vertices.push_back(glm::vec3(min.x, min.y, 0.0));  // Bottom Left
		originalVertices = vertices;
	};
	// Override
	void Update();
	void SetPosition(glm::vec3);
	void SetRotation(glm::vec3);
	bool Collide(Collider*);
	bool Collide(ColliderAABB*);
	bool Collide(ColliderOOBB*);
	// Generate NarrowCollider
	//void GenerateNarrowCollider(CollisionManager& manager, ColliderType type);
private:
	std::vector< glm::vec3> originalVertices;

};