#include "pch.h"

void ColliderOOBB::Update()
{
	//std::vector< glm::vec4> tempVertices;
	glm::mat4 transform = glm::mat4(1);
	transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
	transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
	transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));

	// 4 vertices
	for (int i = 0; i < vertices.size(); i++)
	{
		vertices[i] = transform * glm::vec4(originalVertices[i], 1.0);
		//std::cout << "rotate: " << rotation.x << ", " << rotation.y << ", " << rotation.z << std::endl;
		//std::cout << "transform: " << transform[0][0] << std::endl;
		//std::cout << "vert[" << i << "]: " << vertices[i].x << ", " << vertices[i].y << ", " << vertices[i].z << std::endl
		//	<< std::endl;
	}
}

void ColliderOOBB::SetPosition(glm::vec3 newPosition)
{
	position = newPosition;
}

void ColliderOOBB::SetRotation(glm::vec3 newRotation)
{
	rotation = newRotation;
}

bool ColliderOOBB::Collide(Collider* collided)
{
	return collided->Collide(dynamic_cast<ColliderOOBB*>(this));
}

bool ColliderOOBB::Collide(ColliderAABB* collided)
{
	
	return collided->Collide(dynamic_cast<ColliderOOBB*>(this));
}

bool ColliderOOBB::Collide(ColliderOOBB* collided)
{
	Collider* colliderA = collided;
	Collider* colliderB = this;
	for (int i = 0; i < colliderA->GetVertices().size(); i++)
	{
		glm::vec3 edge = colliderA->GetVertices()[(i + 1) % colliderA->GetVertices().size()] - colliderA->GetVertices()[i];
		glm::vec3 axis = glm::vec3(-edge.y, edge.x, 0.0);
		axis = glm::normalize(axis);

		glm::vec3 vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[0];
		float minA = glm::dot(vertexPosition, axis)
			, maxA = glm::dot(vertexPosition, axis);

		// Project colliderA to axis
		for (int j = 1; j < colliderA->GetVertices().size(); j++)
		{
			vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minA = min(minA, proj);
			maxA = max(maxA, proj);
		}
		vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[0];
		float minB = glm::dot(vertexPosition, axis)
			, maxB = glm::dot(vertexPosition, axis);
		// Project colliderB to axis
		for (int j = 1; j < colliderB->GetVertices().size(); j++)
		{
			vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minB = min(minB, proj);
			maxB = max(maxB, proj);
		}
		if (minA >= maxB || minB >= maxA)
		{
			return false;
		}
	}
	// Loop through VerticesB
	for (int i = 0; i < colliderB->GetVertices().size(); i++)
	{
		glm::vec3 edge = colliderB->GetVertices()[(i + 1) % colliderB->GetVertices().size()] - colliderB->GetVertices()[i];
		glm::vec3 axis = glm::vec3(-edge.y, edge.x, 0.0);
		axis = glm::normalize(axis);
	
		glm::vec3 vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[0];
		float minA = glm::dot(vertexPosition, axis)
			, maxA = glm::dot(vertexPosition, axis);
	
		// Project colliderA to axis
		for (int j = 1; j < colliderA->GetVertices().size(); j++)
		{
			vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minA = min(minA, proj);
			maxA = max(maxA, proj);
		}
		vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[0];
		float minB = glm::dot(vertexPosition, axis)
			, maxB = glm::dot(vertexPosition, axis);
		// Project colliderB to axis
		for (int j = 1; j < colliderB->GetVertices().size(); j++)
		{
			vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minB = min(minB, proj);
			maxB = max(maxB, proj);
		}
		if (minA >= maxB || minB >= maxA)
		{
			return false;
		}
	}
	return true;
}

//void ColliderOOBB::GenerateNarrowCollider(CollisionManager& manager, ColliderType type)
//{
//}
