#pragma once

#include "pch.h"

// Note: to be able to have many of collision group

struct NarrowMessage
{
	NarrowMessage(Collider* _a, Collider* _b) : a(_a), b(_b) {};
	Collider* a;
	Collider* b;
};


struct CollideMessage
{
	Collider* subject;
	std::vector<Collider*> collided;
};

class CollisionManager
{
public:
	CollisionManager() {};
	~CollisionManager();
	Collider* SpawnCollider(ColliderType type, ComponentPhysics* ownerComp, float width, float height);
	void Update();
	void DeleteCollider(Collider* collider);
	void BoardcastCollisionMessage();
	void BoardScan();
	void NarrowScan();
	bool DetectCollision(ColliderAABB* a, ColliderAABB* b);
private:
	std::map<unsigned int, Collider*> colliders;
	std::vector<NarrowMessage> narrowColliders;
	std::vector<CollideMessage> collisions;
	static unsigned int MAX_COLLIDER_ID;
	//unsigned int MAX_COLLIDER_ID;
};