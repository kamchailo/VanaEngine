#include "pch.h"
#include "CollisionManager.h"

unsigned int CollisionManager::MAX_COLLIDER_ID = 0;

CollisionManager::~CollisionManager()
{
	for (const auto& collider : colliders)
	{
		delete (collider.second);
	}
}

Collider* CollisionManager::SpawnCollider(ColliderType type, float width, float height)
{
	Collider* collider = NULL;
	int id = ++MAX_COLLIDER_ID;
	switch (type)
	{
	case COLLIDER_AABB:
		collider = new ColliderAABB(id, glm::vec3(-width/2.0, -height/2.0, 0.0), glm::vec3(width/2.0, height/2.0, 0.0));
		//collider = new ColliderAABB(id, glm::vec3(-width, -height , 0.0), glm::vec3(width, height, 0.0));
		collider->narrowCollider = new ColliderOOBB(id, glm::vec3(-width / 2.0, -height / 2.0, 0.0), glm::vec3(width / 2.0, height / 2.0, 0.0));
		break;
	case COLLIDER_OOBB:
		collider = new ColliderOOBB(id, glm::vec3(-width / 2.0, -height / 2.0, 0.0), glm::vec3(width / 2.0, height / 2.0, 0.0));
		break;
	case COLLIDER_CIRCLE:
		break;
	default:
		break;
	}
	if (collider)
	{
		colliders[id] = collider;
	}
	return collider;
}

void CollisionManager::Update()
{
	narrowColliders.clear();
	for (auto& colliderI : colliders)
	{
		colliderI.second->Update();
		//delete (&collider);
		colliderI.second->ResetCollided();
	}
	BoardScan();
	NarrowScan();
}

void CollisionManager::DeleteCollider(Collider* collider)
{
	colliders.erase(collider->colliderID);
	delete collider;
}

void CollisionManager::BoardcastCollisionMessage(Collider* subject)
{

}

void CollisionManager::BoardScan()
{
	// do board scan
	for (auto& colliderI : colliders)
	{
		for (auto& colliderJ : colliders)
		{
			if (colliderI != colliderJ)
			{
				// if (colliderI.collide(colliderJ))
				if (colliderI.second->Collide(colliderJ.second))
				{
					//std::cout << "FOUND COLLISION" << std::endl;
					narrowColliders.push_back(NarrowMessage(colliderI.second, colliderJ.second));
				}


				//if (colliderI.second->type == COLLIDER_AABB && colliderJ.second->type == COLLIDER_AABB)
				//{


				//	if (DetectCollision(dynamic_cast<ColliderAABB*>(colliderI.second), dynamic_cast<ColliderAABB*>(colliderJ.second)))
				//	{
				//		std::cout << "FOUND COLLISION" << std::endl;
				//		// colliderI board collide with colliderJ
				//		narrowColliders.push_back(NarrowMessage(colliderI.second, colliderJ.second));
				//	}
				//}
			}
		}
	}
}

void CollisionManager::NarrowScan()
{
						//colliderI.second->AddCollided(colliderJ.second);
	for (int i = 0; i < narrowColliders.size(); i++)
	{
		//std::cout << "inside narrow scan " << narrowColliders[i].a->colliderID << " with " << narrowColliders[i].b->colliderID << std::endl;
		Collider* colliderA = narrowColliders[i].a;
		Collider* colliderB = narrowColliders[i].b;
		if (narrowColliders[i].a->narrowCollider)
		{
			//std::cout << "A has narrow" << std::endl;
			colliderA = narrowColliders[i].a->narrowCollider;
		}
		if (narrowColliders[i].b->narrowCollider)
		{
			//std::cout << "B has narrow" << std::endl;
			colliderB = narrowColliders[i].b->narrowCollider;
		}
		//if (colliderA == narrowColliders[i].a && colliderB == narrowColliders[i].b)
		//{
		//	//std::cout << "NARROW FOUND COLLISION" << std::endl;
		//	colliderA->AddCollided(colliderB);
		//	continue;
		//}
		colliderA->SetPosition(narrowColliders[i].a->GetPosition());
		colliderA->SetRotation(narrowColliders[i].a->GetRotation());
		colliderA->Update();
		colliderB->SetPosition(narrowColliders[i].b->GetPosition());
		colliderB->SetRotation(narrowColliders[i].b->GetRotation());
		colliderB->Update();
		if (colliderA->Collide(colliderB))
		{
			//std::cout << "NARROW FOUND COLLISION" << std::endl;
			narrowColliders[i].a->AddCollided(colliderB);
		}
	}
}

// @@ Need to be moved to Collider
bool CollisionManager::DetectCollision(ColliderAABB* a, ColliderAABB* b)
{
	float d1x = b->GetMinPoint().x - a->GetMaxPoint().x;
	float d1y = b->GetMinPoint().y - a->GetMaxPoint().y;
	float d2x = a->GetMinPoint().x - b->GetMaxPoint().x;
	float d2y = a->GetMinPoint().y - b->GetMaxPoint().y;
	
	//std::cout << "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvv" << std::endl;
	//std::cout << "==============================" << std::endl;
	//std::cout << "a Pos: " << a->GetPosition().x << ", " << a->GetPosition().y << std::endl;
	//std::cout << "b Pos: " << b->GetPosition().x << ", " << b->GetPosition().y << std::endl;
	//std::cout << "b minX: " << b->GetMinPoint().x << " a maxX :" << a->GetMaxPoint().x << " d1x: " << d1x << std::endl;
	//std::cout << "b minY: " << b->GetMinPoint().y << " a maxY :" << a->GetMaxPoint().y << " d1y: " << d1y << std::endl;
	//std::cout << "a minX: " << a->GetMinPoint().x << " b maxX :" << b->GetMaxPoint().x << " d2x: " << d2x << std::endl;
	//std::cout << "a minY: " << a->GetMinPoint().y << " b maxY :" << b->GetMaxPoint().y << " d2y: " << d2y << std::endl;
	//std::cout << "==============================" << std::endl;
	//std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;

	if (d1x > 0.0f || d1y > 0.0f)
	{
		return FALSE;
	}
	if (d2x > 0.0f || d2y > 0.0f)
	{
		return FALSE;
	}
	return TRUE;
}