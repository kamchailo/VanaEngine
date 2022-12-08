#include "pch.h"
#include "CollisionManager.h"
#include "VanaEngine.h"

unsigned int CollisionManager::MAX_COLLIDER_ID = 0;

CollisionManager::~CollisionManager()
{
	/*
	* Let PhysicsComponent delete their collider
	for (const auto& collider : colliders)
	{
		delete (collider.second);
	}
	*/
}

Collider* CollisionManager::SpawnCollider(ColliderType type, ComponentPhysics* ownerComp, float width, float height)
{
	Collider* collider = NULL;
	int id = ++MAX_COLLIDER_ID;
	switch (type)
	{
	case COLLIDER_AABB:
		collider = new ColliderAABB(id
			, ownerComp
			, glm::vec3(-width/2.0, -height/2.0, 0.0)
			, glm::vec3(width/2.0, height/2.0, 0.0));
		//collider = new ColliderAABB(id, glm::vec3(-width, -height , 0.0), glm::vec3(width, height, 0.0));
		
		// @@ turn off OOBB
		collider->narrowCollider = new ColliderOOBB(id
			, ownerComp
			, glm::vec3(-width / 2.0, -height / 2.0, 0.0)
			, glm::vec3(width / 2.0, height / 2.0, 0.0));
		
		break;
	case COLLIDER_OOBB:
		collider = new ColliderOOBB(id
			, ownerComp
			, glm::vec3(-width / 2.0, -height / 2.0, 0.0)
			, glm::vec3(width / 2.0, height / 2.0, 0.0));
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

Collider* CollisionManager::SpawnColliderInLayer(int selfLayer, int targetLayer, ColliderType type, ComponentPhysics* ownerComp, float width, float height)
{
	


	Collider* collider = NULL;
	int id = ++MAX_COLLIDER_ID;
	switch (type)
	{
	case COLLIDER_AABB:
		collider = new ColliderAABB(id
			, ownerComp
			, glm::vec3(-width / 2.0, -height / 2.0, 0.0)
			, glm::vec3(width / 2.0, height / 2.0, 0.0));
		//collider = new ColliderAABB(id, glm::vec3(-width, -height , 0.0), glm::vec3(width, height, 0.0));
		/*
		* @@ turn off OOBB
		*/
		collider->narrowCollider = new ColliderOOBB(id
			, ownerComp
			, glm::vec3(-width / 2.0, -height / 2.0, 0.0)
			, glm::vec3(width / 2.0, height / 2.0, 0.0));
		break;
	case COLLIDER_OOBB:
		collider = new ColliderOOBB(id
			, ownerComp
			, glm::vec3(-width / 2.0, -height / 2.0, 0.0)
			, glm::vec3(width / 2.0, height / 2.0, 0.0));
		break;
	case COLLIDER_CIRCLE:
		break;
	default:
		break;
	}
	if (collider)
	{
		//colliders[id] = collider;
		collider->selfLayer = selfLayer;
		collider->targerLayer = targetLayer;
		colliderLayers[selfLayer][id] = collider;
	}
	return collider;
}

void CollisionManager::Init()
{
	colliderLayers.resize(5);

}

void CollisionManager::Update()
{
	narrowColliders.clear();
	//for (auto& colliderI : colliders)
	//{
	//	colliderI.second->Update();
	//	//delete (&collider);
	//	colliderI.second->ResetCollided();
	//}
	for (auto& clayer : colliderLayers)
	{
		for (auto& c : clayer)
		{
			c.second->Update();
			c.second->ResetCollided();
		}
	}

	//BoardScan();
	BoardScanLayers();
	NarrowScan();
	//BoardcastCollisionMessage();
}

void CollisionManager::DeleteCollider(Collider* collider)
{
	//colliders.erase(collider->colliderID);
	colliderLayers[collider->selfLayer].erase(collider->colliderID);
	delete collider;
}

void CollisionManager::BoardcastCollisionMessage()
{
	// @@ Optimized by remove non-collided collider
	for (int i = 0; i < narrowColliders.size(); ++i)
	{
		if (narrowColliders[i].a->GetCollideds().size() > 0)
		{
			EventCollision* e = new EventCollision(new EventCollisionMessage(narrowColliders[i].a));
			Vana::coreEventManager.AddEvent(e);
		}
	}
}

void CollisionManager::BoardScan()
{
	std::map<unsigned int, Collider*>::iterator itI, itJ;
	itI = colliders.begin();
	while (itI != colliders.end())
	{
		itJ = itI;
		while (itJ != colliders.end())
		{
			if (itI != itJ) 
			{
				if (itI->second->Collide(itJ->second))
				{
					narrowColliders.push_back(NarrowMessage(itI->second, itJ->second));
				}
				
			}
			++itJ;
		}
		++itI;
	}
}

void CollisionManager::BoardScanLayers()
{
	std::map<unsigned int, Collider*>::iterator itC, itT;
	for (int i = 0; i < colliderLayers.size() - 1; ++i)
	{
		// for each colliders in colliderLayer[i]
		for (auto& c : colliderLayers[i])
		{
			//std::vector<Collider*>* targetLayer = &colliderLayers[c->targerLayer];
			// for each colliders in targetLayer

			for (auto& t : colliderLayers[c.second->targerLayer])
			{
				if (c.second->colliderID != t.second->colliderID)
				{
					if (c.second->Collide(t.second))
					{
						// Collide
						//std::cout << "Collision " << c.second->colliderID << " with " << t.second->colliderID << std::endl;
					
						narrowColliders.push_back(NarrowMessage(c.second, t.second));
					}
				}
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
			// @@ optimized by add both
			narrowColliders[i].a->AddCollided(colliderB);
			//narrowColliders[i].b->AddCollided(colliderA);
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