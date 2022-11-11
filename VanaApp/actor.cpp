#include "actor.h"
#include <MeshCollection.h>
#include <Input.h>

float i = 0;
//float x = 400, y = 400;
float x = 0, y = 0;
Actor::Actor(Vana::Node* parent, Texture* tex, glm::vec2 spriteSize) : Node(parent)
{
	ComponentTransform* ct = new ComponentTransform();
	ComponentRenderer* cr = new ComponentRenderer(tex, spriteSize);
	ComponentPhysics* cp = new ComponentPhysics(Vana::collisionManager, spriteSize);
	this->AddComponent(ct);
	this->AddComponent(cr);
	this->AddComponent(cp);
}

void Actor::Init()
{
	//this->Scale(glm::vec3(1.0, 0.2, 1.0));
}

void Actor::Update()
{
	if (Input::GetInstance()->IsPressed(INPUT_KEY_UP))
	{
		//std::cout << "UP is pressed" << std::endl;
		y += 0.1;
	}
	if (Input::GetInstance()->IsPressed(INPUT_KEY_DOWN))
	{
		//std::cout << "UP is pressed" << std::endl;
		y += -0.1;
	}
	if (Input::GetInstance()->IsPressed(INPUT_KEY_LEFT))
	{
		//std::cout << "UP is pressed" << std::endl;
		x += -0.1;
	}
	if (Input::GetInstance()->IsPressed(INPUT_KEY_RIGHT))
	{
		//std::cout << "UP is pressed" << std::endl;
		x += 0.1;
	}
	//std::cout << "BBB";
	//SetPosition(glm::vec3(x, y, 0));

	PhysicsBody* bod = GetComponent<ComponentPhysics>()->body;

	bod->SetVelocity(glm::vec3(x, y, 0));


	if (Input::GetInstance()->IsPressed(INPUT_KEY_INTERACT))
	{
		i -= 0.1;
	}
	SetRotation(glm::vec3(0.0, 0.0, i));

}
