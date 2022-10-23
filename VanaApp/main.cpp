#include <VanaEngine.h>

#include "actor.h"
#include "ActorChild.h"

float vert1[] =
{
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};


float rect[] =
{
	 0.5f,  0.5f, 0.0f,  // 0 - top right
	 0.5f, -0.5f, 0.0f,  // 1 - bottom right
	-0.5f, -0.5f, 0.0f,  // 2 - bottom left
	-0.5f,  0.5f, 0.0f   // 3 - top left 
};

unsigned int indices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};




int main()
{
	Vana::Init(800, 600);


	Mesh* triMesh = new Mesh(vert1, sizeof(vert1));
	Mesh* rectMesh = new Mesh(rect, sizeof(rect), indices, sizeof(indices));

	Texture* tex = new Texture("../resources/textures/sharkey.jpg");

	Collider* aAABB = Vana::collisionManager.SpawnCollider(COLLIDER_AABB, 100, 200);
	aAABB->GenerateNarrowCollider(Vana::collisionManager, COLLIDER_OOBB);
	Collider* bAABB = Vana::collisionManager.SpawnCollider(COLLIDER_AABB, 300, 100);
	bAABB->GenerateNarrowCollider(Vana::collisionManager, COLLIDER_OOBB);
	Collider* cAABB = Vana::collisionManager.SpawnCollider(COLLIDER_AABB, 100, 100);
	cAABB->GenerateNarrowCollider(Vana::collisionManager, COLLIDER_OOBB);


	Actor* a = new Actor(Vana::root, tex, glm::vec2(100,200));
	//a->SetPosition(glm::vec3(-50, -50, 0));
	a->collider = aAABB;
	ActorChild* b = new ActorChild(Vana::root, tex, glm::vec2(300, 100));
	b->collider = bAABB;
	b->SetPosition(glm::vec3(200, 200, 0.0));

	ActorChild* c = new ActorChild(Vana::root, tex, glm::vec2(100, 100));
	c->collider = cAABB;
	c->SetPosition(glm::vec3(-50, 200, 0.0));

	//b->SetScale(glm::vec3(1.5, 1.5, 1.0));
	//b->SetScale(glm::vec3(2));

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);s
	//Collider* collider = Vana::collisionManager.SpawnCollider(COLLIDER_AABB, 100, 100);

	Vana::Update();


	return 0;
}

