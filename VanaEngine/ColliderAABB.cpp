#include "pch.h"
#include "ColliderAABB.h"

void ColliderAABB::Update()
{

	// Recalculate bounding box
	// new maxPoint and minPoint
	// simulate 4 point
	// create new max, min
	// 
	std::vector< glm::vec4> tempVertices;
	glm::mat4 transform = glm::mat4(1);
	transform = glm::rotate(transform, glm::radians(rotation.x), glm::vec3(1.0, 0.0, 0.0));
	transform = glm::rotate(transform, glm::radians(rotation.y), glm::vec3(0.0, 1.0, 0.0));
	transform = glm::rotate(transform, glm::radians(rotation.z), glm::vec3(0.0, 0.0, 1.0));

	minPoint.x = 0.0;
	minPoint.y = 0.0;
	maxPoint.x = 0.0;
	maxPoint.y = 0.0;

	// 4 vertices
	for (int i = 0; i < vertices.size(); i++)
	{
		tempVertices.push_back(transform * glm::vec4(vertices[i],1.0));
		minPoint.x = min(minPoint.x, tempVertices[i].x);
		minPoint.y = min(minPoint.y, tempVertices[i].y);
		maxPoint.x = max(maxPoint.x, tempVertices[i].x);
		maxPoint.y = max(maxPoint.y, tempVertices[i].y);
		//std::cout << "vert[" << i << "]: " << tempVertices[i].x << ", " << tempVertices[i].y << ", " << tempVertices[i].z << std::endl
		//	<< " minPoint: " << minPoint.x << ", " << minPoint.y
		//	<< " maxPoint: " << maxPoint.x << ", " << maxPoint.y
		//	<< std::endl;
	}
	// Boardcast message
	if (collideds.size() > 0)
	{
		std::cout << "YELLING THAT Collider[" << colliderID << "] has collision with " << collideds.size() << " colliders" << std::endl;
	}

}

void ColliderAABB::SetPosition(glm::vec3 newPosition)
{
	position = newPosition;
}

void ColliderAABB::SetRotation(glm::vec3 newRotation)
{
	rotation = newRotation;
}

bool ColliderAABB::Collide(Collider* collided)
{
	return collided->Collide(dynamic_cast<ColliderAABB*>(this));
}

bool ColliderAABB::Collide(ColliderAABB* collided)
{
	// Check AABB with AABB
	float d1x = collided->GetMinPoint().x - this->GetMaxPoint().x;
	float d1y = collided->GetMinPoint().y - this->GetMaxPoint().y;
	float d2x = this->GetMinPoint().x - collided->GetMaxPoint().x;
	float d2y = this->GetMinPoint().y - collided->GetMaxPoint().y;
	if (d1x > 0.0f || d1y > 0.0f)
	{
		return false;
	}
	if (d2x > 0.0f || d2y > 0.0f)
	{
		return false;
	}
	return true;
}

bool ColliderAABB::Collide(ColliderOOBB* collided)
{
	// loop though vertices (edge)
		// find edge vi - vi+1 < normalize
	Collider* colliderA = collided;
	Collider* colliderB = this;
		//std::vector<glm::vec3>& colliderA = collided->GetVertices();
		//std::vector<glm::vec3>& colliderB = this->vertices;
	//if (this->vertices.size() > collided->GetVertices().size())
	//{
	//	// colliderA will always has less edge
	//	colliderA = this->vertices;
	//	colliderB = collided->GetVertices();
	//}
	// Loop through VerticesA
	for (int i = 0; i < colliderA->GetVertices().size(); i++)
	{
		glm::vec3 edge = colliderA->GetVertices()[(i + 1) % colliderA->GetVertices().size()] - colliderA->GetVertices()[i];
		glm::vec3 axis = glm::vec3(-edge.y, edge.x, 0.0);

		axis = glm::normalize(axis);
		//std::cout << "==================================================" << std::endl
		//	<< "axis: " << axis.x << ", " << axis.y << ", " << axis.z << std::endl
		//	<< "Vertices A" << std::endl;
		

		glm::vec3 vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[0];
		float minA = glm::dot(vertexPosition, axis)
			, maxA = glm::dot(vertexPosition, axis);
		//std::cout << "Proj: " << glm::dot(vertexPosition, axis) << " verticesA[" << 0 << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;

		// Project colliderA to axis
		for (int j = 1; j < colliderA->GetVertices().size(); j++)
		{
			vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minA = min(minA, proj);
			maxA = max(maxA, proj);
			//std::cout << "Proj: " << proj << " verticesA[" << j << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		}
		//std::cout << "--------------------------------------------------" << std::endl;
		vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[0];
		float minB = glm::dot(vertexPosition, axis)
			, maxB = glm::dot(vertexPosition, axis);
		//std::cout << "Proj: " << glm::dot(vertexPosition, axis) << " verticesB[" << 0 << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		// Project colliderB to axis
		for (int j = 1; j < colliderB->GetVertices().size(); j++)
		{
			vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minB = min(minB, proj);
			maxB = max(maxB, proj);
			//std::cout << "Proj: " << proj << " verticesB[" << j << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		}
		if (minA >= maxB || minB >= maxA)
		{
			return false;
		}
		//std::cout << " >>>>>>>> AABB with OOBB <<<<<<<<" << std::endl
		//	<< (minA >= maxB) << " minA: " << minA << " >= maxB: " << maxB << std::endl
		//	<< (minB >= maxA) << " minB: " << minB << " >= maxA: " << maxA << std::endl;
	}
	// Loop through VerticesB
	for (int i = 0; i < colliderB->GetVertices().size(); i++)
	{
		glm::vec3 edge = colliderB->GetVertices()[(i + 1) % colliderB->GetVertices().size()] - colliderB->GetVertices()[i];
		glm::vec3 axis = glm::vec3(-edge.y, edge.x, 0.0);
		axis = glm::normalize(axis);
		//std::cout << "==================================================" << std::endl
		//	<< "axis: " << axis.x << ", " << axis.y << ", " << axis.z << std::endl
		//	<< "Vertices B : " << std::endl;
	
		glm::vec3 vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[0];
		float minA = glm::dot(vertexPosition, axis)
			, maxA = glm::dot(vertexPosition, axis);
		//std::cout << "Proj: " << glm::dot(vertexPosition, axis) << " verticesA[" << 0 << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		

		// Project colliderA to axis
		for (int j = 1; j < colliderA->GetVertices().size(); j++)
		{
			vertexPosition = colliderA->GetPosition() + colliderA->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minA = min(minA, proj);
			maxA = max(maxA, proj);
			//std::cout << "Proj: " << proj << " verticesA[" << j << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		}
		//std::cout << "--------------------------------------------------" << std::endl;
		vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[0];
		float minB = glm::dot(vertexPosition, axis)
			, maxB = glm::dot(vertexPosition, axis);
		//std::cout << "Proj: " << glm::dot(vertexPosition, axis) << " verticesB[" << 0 << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		// Project colliderB to axis
		for (int j = 1; j < colliderB->GetVertices().size(); j++)
		{
			vertexPosition = colliderB->GetPosition() + colliderB->GetVertices()[j];
			float proj = glm::dot(vertexPosition, axis);
			minB = min(minB, proj);
			maxB = max(maxB, proj);
			//std::cout << "Proj: " << proj << " verticesB[" << j << "]: " << vertexPosition.x << ", " << vertexPosition.y << ", " << vertexPosition.z << std::endl;
		}
		if (minA >= maxB || minB >= maxA)
		{
			return false;
		}
		//std::cout << " >>>>>>>> AABB with OOBB <<<<<<<<" << std::endl
		//	<< (minA >= maxB) << " minA: " << minA << " >= maxB: " << maxB << std::endl
		//	<< (minB >= maxA) << " minB: " << minB << " >= maxA: " << maxA << std::endl;
	}
	//std::cout << "OOBB collided" << std::endl;
	return true;
}

//void ColliderAABB::GenerateNarrowCollider(CollisionManager& manager, ColliderType type)
//{
//}

glm::vec3 ColliderAABB::GetMinPoint() const
{
	// to supprt custom scale
	// return position + (minPoint * scale);
	return position + minPoint;
}

glm::vec3 ColliderAABB::GetMaxPoint() const
{
	return position + maxPoint;
}