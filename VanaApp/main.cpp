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

	Texture* tex = new Texture("../resources/textures/sharkey.jpg");

	Vana::Node* nodeA = new Vana::Node(Vana::root);
	ComponentTransform* trnfA = new ComponentTransform();
	ComponentRenderer* rendA = new ComponentRenderer(tex, glm::vec2(100, 100));
	ComponentPhysics* physA = new ComponentPhysics(Vana::collisionManager, glm::vec2(100, 100));
	nodeA->AddComponent(trnfA);
	nodeA->AddComponent(rendA);
	nodeA->AddComponent(physA);
	nodeA->SetPosition(glm::vec3(-200, 100, 0.0));

	//Moving guys
	Actor* b = new Actor(Vana::root, tex, glm::vec2(200, 50));

	Vana::Node* nodebb = new Vana::Node(Vana::root);
	ComponentTransform* trnfBb = new ComponentTransform();
	ComponentRenderer* rendBb = new ComponentRenderer(tex, glm::vec2(50, 50));
	ComponentPhysics* physBb = new ComponentPhysics(Vana::collisionManager, glm::vec2(50, 50));
	nodebb->AddComponent(trnfBb);
	nodebb->AddComponent(rendBb);
	nodebb->AddComponent(physBb);

	nodebb->SetPosition(glm::vec3(200, 100, 0.0));
	nodebb->SetRotation(glm::vec3(0, 0, 40));



	//Actor* c = new Actor(b, tex, glm::vec2(75, 75));
	


	//std::cout << b->nodeID << std::endl;
	//std::cout << nodebb->GetParent()->nodeID << std::endl;

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	Vana::Update();


	return 0;
}

