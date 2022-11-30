#include "actor.h"
#include <MeshCollection.h>
#include <Input.h>
#include "ActorDebug.h"
#include "Enemy.h"

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
}

void Actor::Init()
{
	this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(idle);
	this->GetComponent<ComponentAnimator2D>()->Play();

	//this->Scale(glm::vec3(1.0, 0.2, 1.0));
	this->SetPosition(glm::vec3(0, 0, 0));
}

void Actor::Update(double _dt)
{
	// Catch if state == DEAD
	if (state == Actor::DEAD)
	{
		std::cout << "I'm DEAD" << std::endl;
		return;
	}

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

	// Create direction
	//glm::vec3 dir = glm::vec3(x, y, 0);
	//if (glm::length(dir) > 0)
	//{
	//	dir = glm::normalize(dir);
	//}
	//dir *= speedStep * 1000 * _dt;
	//direction += dir;
	//direction = glm::clamp(direction, glm::vec3(-maxSpeed), glm::vec3(maxSpeed));
	//std::cout << "x,y : " << direction.x <<", "<< direction.y << std::endl;
	//std::cout << "x,y : " << direction.x << ", " << direction.y 
	//	<< " || glm::length(direction) : " << glm::length(direction) << std::endl;


	// Create normalized direction
	direction = glm::vec3(x, y, 0);
	if (glm::length(direction) > 0)
	{
		direction = glm::normalize(direction);
	}


	// Update Velocity
	// Make Body Move
	if (x != 0 || y != 0)
	{
		speed = min(maxSpeed, speed + speedStep * _dt);
		bod->SetVelocity(direction * speed * dashSpeed);
	}
	else
	{
		speed = 0;
		glm::vec3 curV = bod->GetVelocity();
		glm::vec3 dampen = glm::vec3(
			max(0.0, curV.x - speedStep * _dt)
			, max(0.0, curV.y - speedStep * _dt)
			, 0.0
		);
		bod->SetVelocity(dampen);
	}

	// dampen
	//speed = max(1.0, speed - maxSpeed * 20 * _dt);
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
	actorDebug->SetText4(
		+ " speed "
		+ std::to_string(speed)
		+ " move "
		+ std::to_string(direction.x * speed * dashSpeed));


	// Trigger when collide with something

	std::vector<Collider*> collideds = this->GetComponent<ComponentPhysics>()->body
		->GetCollider()->GetCollideds();
	if (SceneSystem::GetInstance()->GetCurrentScene() == mainScene
		&&
		collideds.size() > 0)
	{
		for (auto& c : collideds)
		{
			// collided with 
			// DiamondHead
			Node* n = dynamic_cast<DiamondHead*>(c->GetOwnerComponent()->GetOwner());
			if (n)
			{
				if (isDashing)
				{
					std::cout << " Hit Diamond Head" << std::endl;
					n->Destroy();
				}
				else
				{
					state = Actor::DEAD;
				}
				continue;
			}
			// collided with 
			// DiamondArrow
			n = dynamic_cast<DiamondArrow*>(c->GetOwnerComponent()->GetOwner());
			if (n)
			{
				if (isDashing)
				{
					std::cout << " Hit Diamond Arrow" << std::endl;
					// destroy
					n->Destroy();
				}
				else
				{
					state = Actor::DEAD;

				}
				continue;
			}
		}
		//SceneSystem::GetInstance()->GetCurrentScene()->Reset();
		//std::cout << "Game End" << std::endl;
		//SceneSystem::GetInstance()->SwitchScene(endScene);
		//Actor* c = new Actor(texPlayer, glm::vec2(100, 100));
		//endScene->AddExtendedNode(c);
	}

}
