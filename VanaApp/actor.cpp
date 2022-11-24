#include "actor.h"
#include <MeshCollection.h>
#include <Input.h>
#include "ActorDebug.h"

#include "global.h"

float i = 0;
//float x = 400, y = 400;
float x = 0, y = 0;
Actor::Actor(Texture* tex, glm::vec2 spriteSize) 
	: Node()
	, idleTex(tex)
{
	ComponentTransform* ct = new ComponentTransform();
	ComponentRenderer* cr = new ComponentRenderer(tex, spriteSize);
	ComponentPhysics* cp = new ComponentPhysics(Vana::collisionManager, spriteSize);
	this->AddComponent(ct);
	this->AddComponent(cr);
	this->AddComponent(cp);
	bod = GetComponent<ComponentPhysics>()->body;
	actorDebug = new ActorDebug("ActorDebug", 200, 100);
	Vana::gameUI->AddUiWindow(actorDebug);
}

void Actor::Init()
{
	ComponentAnimator2D* compAnim2D = new ComponentAnimator2D();
	this->AddComponent(compAnim2D);
	idle = new Animation2D(idleTex, 4, 4, true, true);
	idle->AddKeyFrame(0, 0);
	idle->AddKeyFrame(1, 1);
	idle->AddKeyFrame(1, 1);
	idle->AddKeyFrame(2, 2);
	idle->AddKeyFrame(3, 3);
	idle->AddKeyFrame(4, 4);
	idle->AddKeyFrame(5, 5);
	idle->AddKeyFrame(6, 6);
	idle->AddKeyFrame(7, 7);
	idle->AddKeyFrame(8, 8);
	idle->AddKeyFrame(9, 9);
	idle->AddKeyFrame(10, 10);
	idle->AddKeyFrame(11, 11);
	idle->AddKeyFrame(12, 12);
	idle->AddKeyFrame(13, 13);
	idle->AddKeyFrame(14, 14);
	idle->AddKeyFrame(15, 15);
	idle->SetMaxDuration(16.0);
	this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(idle);
	this->GetComponent<ComponentAnimator2D>()->Play();

	//this->Scale(glm::vec3(1.0, 0.2, 1.0));
	this->SetPosition(glm::vec3(0, 0, 0));
}

void Actor::Update(double _dt)
{
	glm::vec3 pos = this->GetPosition();
	//std::cout << "position : " << pos.x << ", " << pos.y << std::endl;

	float horizontalBound = 400;
	float verticalBound = 300;

	// Set Bound
	if (pos.x < -horizontalBound)
	{
		this->SetPosition(glm::vec3(-horizontalBound, pos.y, pos.z));
	}
	if (pos.x > horizontalBound)
	{
		this->SetPosition(glm::vec3(horizontalBound, pos.y, pos.z));
	}
	if (pos.y < -verticalBound)
	{
		this->SetPosition(glm::vec3(pos.x, -verticalBound, pos.z));
	}
	if (pos.y > verticalBound)
	{
		this->SetPosition(glm::vec3(pos.x, verticalBound, pos.z));
	}


	x = 0;
	y = 0;
	// X direction
	if (Input::GetInstance()->IsPressed(INPUT_KEY_UP))
	{
		y = 1;
	}
	else if (Input::GetInstance()->IsPressed(INPUT_KEY_DOWN))
	{
		y = -1;
	}

	// Y direction
	if (Input::GetInstance()->IsPressed(INPUT_KEY_LEFT))
	{
		x = -1;
	}
	else if (Input::GetInstance()->IsPressed(INPUT_KEY_RIGHT))
	{
		x = 1;
	}

	//if (x != 0 || y != 0)
	//{
	//	speed = max(maxSpeed , speed + speedStep * _dt);
	//}

	if (Input::GetInstance()->IsPressed(INPUT_KEY_INTERACT) && !isDashing && coolDown == 0)
	{
		dashSpeed = dashActive;
		isDashing = true;
		coolDown = maxCoolDown;
	}

	//std::cout << "speed : " << speed << std::endl;


	//std::cout << "BBB";
	//SetPosition(glm::vec3(x, y, 0));


	// Recalc Speed
	// if move
	// speed += step





	// Create direction
	glm::vec3 dir = glm::vec3(x, y, 0);
	if (glm::length(dir) > 0)
	{
		dir = glm::normalize(dir);
	}
	dir *= speedStep * 1000 * _dt;
	direction += dir;
	direction = glm::clamp(direction, glm::vec3(-maxSpeed), glm::vec3(maxSpeed));
	//std::cout << "x,y : " << direction.x <<", "<< direction.y << std::endl;
	//std::cout << "x,y : " << direction.x << ", " << direction.y 
	//	<< " || glm::length(direction) : " << glm::length(direction) << std::endl;


	// Update Velocity
	// Make Body Move
	bod->SetVelocity(direction * dashSpeed);

	// dampen
	direction.x -= direction.x * speedStep * 0.3 * _dt;
	direction.y -= direction.y * speedStep * 0.3 * _dt;
	//speed = max(0, speed - speedStep * maxSpeed * 2 * _dt);
	coolDown = max(0.0, coolDown - _dt);

	if (isDashing)
	{
		dashSpeed = max(1, dashSpeed - dashActive * 10 * _dt);
		if (dashSpeed == 1)
		{
			isDashing = false;
		}
	}
	else
	{

	}
	//Imgui Debug
	actorDebug->SetText1(std::to_string(isDashing));
	actorDebug->SetText2(std::to_string(coolDown));
	actorDebug->SetText3(std::to_string(x) + " " + std::to_string(y));
	actorDebug->SetText4("direction : " 
		+ std::to_string(direction.x) 
		+ " " 
		+ std::to_string(direction.y));


	// Trigger when collide with something
	if (SceneSystem::GetInstance()->GetCurrentScene() == mainScene
		&&
		this->GetComponent<ComponentPhysics>()->body
		->GetCollider()->GetCollideds().size() > 0)
	{
		//SceneSystem::GetInstance()->GetCurrentScene()->Reset();
		//std::cout << "Game End" << std::endl;
		//SceneSystem::GetInstance()->SwitchScene(endScene);
		//Actor* c = new Actor(texPlayer, glm::vec2(100, 100));
		//endScene->AddExtendedNode(c);
	}

}
