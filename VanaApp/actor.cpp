#include "actor.h"
#include <Graphics/MeshCollection.h>
#include <Input/Input.h>
#include "ActorDebug.h"
#include "Enemy.h"
#include "ScoreSprite.h"
#include "InputListener.h"

#include "global.h"

#include "CallBackFunction.h"

float i = 0;
//float x = 400, y = 400;
float x = 0, y = 0;
int currentScore = 0;
Actor::Actor(Texture* tex, glm::vec2 spriteSize) 
	: Node()
	, idleTex(tex)
{
	ComponentTransform* ct = new ComponentTransform();
	ComponentRenderer* cr = new ComponentRenderer(tex, spriteSize);
	ComponentPhysics* cp = new ComponentPhysics(Vana::collisionManager, spriteSize * 0.6f, 0, 1);
	this->AddComponent(ct);
	this->AddComponent(cr);
	this->AddComponent(cp);
	bod = GetComponent<ComponentPhysics>()->body;

	ComponentAnimator2D* compAnim2D = new ComponentAnimator2D();
	this->AddComponent(compAnim2D);
	idle = new Animation2D(idleTex, 4, 3, true, true);
	idle->SetMaxDuration(0.32);
	idle->AddKeyFrame(0, 8);
	idle->AddKeyFrame(0.8, 9);
	idle->AddKeyFrame(0.16, 10);
	idle->AddKeyFrame(0.24, 9);
	//idle->AddKeyFrame(1.44, 8);
	//idle->AddKeyFrame(9, 9);
	//idle->AddKeyFrame(10, 10);
	//idle->AddKeyFrame(11, 11);
	//idle->AddKeyFrame(12, 12);
	//idle->AddKeyFrame(13, 13);
	//idle->AddKeyFrame(14, 14);
	//idle->AddKeyFrame(15, 15);

	walk = new Animation2D(idleTex, 4, 3, true, true);
	walk->SetMaxDuration(0.64);
	walk->AddKeyFrame(0, 0);
	walk->AddKeyFrame(0.8, 1);
	walk->AddKeyFrame(0.16, 2);
	walk->AddKeyFrame(0.24, 3);
	walk->AddKeyFrame(0.32, 4);
	walk->AddKeyFrame(0.40, 5);
	walk->AddKeyFrame(0.48, 6);
	walk->AddKeyFrame(0.56, 7);

	//dashTex = new Texture("../resources/textures/diamondArrowIdle.png");
	dashAnim = new Animation2D(idleTex, 4, 3, true, true);
	dashAnim->SetMaxDuration(1.0);
	dashAnim->AddKeyFrame(0, 11);


}

void Actor::Init()
{
	this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(idle);
	this->GetComponent<ComponentAnimator2D>()->Play();

	//this->Scale(glm::vec3(1.0, 0.2, 1.0));
	this->SetPosition(glm::vec3(0, 0, 0));

	currentScore = 0.0;
}

void Actor::Update(double _dt)
{
	// Catch if state == DEAD
	if (state == Actor::DEAD)
	{
		// if countdown reach change state
		// start count down
		Dampen(_dt);
		std::cout << "I'm DEAD" << std::endl;

		//SceneSystem::GetInstance()->GetCurrentScene()->Reset();
		SceneSystem::GetInstance()->SwitchScene(endScene);
		ScoreBoard* result = new ScoreBoard(texScore, glm::vec2(100), glm::vec3(50, 50, 0));
		result->SetScore(currentScore);
		endScene->AddExtendedNode(result);
		InputListener* listener = new InputListener(INPUT_KEY_RESET, &ResetGame);
		endScene->AddExtendedNode(listener);
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

	if (Input::GetInstance()->IsPressed(INPUT_KEY_INTERACT) && !isDashing && coolDown == 0 && speed > 0)
	{
		dashSpeed = dashActive;
		isDashing = true;
		coolDown = maxCoolDown;
		speed = maxSpeed;
	}

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
		this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(walk);
	}
	else
	{
		Dampen(_dt);
		this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(idle);
	}

	// dampen
	//speed = max(1.0, speed - maxSpeed * 20 * _dt);
	coolDown = max(0.0, coolDown - _dt);

	if (isDashing)
	{
		dashSpeed = max(1, dashSpeed - dashActive * dashDamped * _dt);
		if (dashSpeed == 1)
		{
			isDashing = false;
		}
		float rotation = atan2(direction.y, direction.x);
		rotation = rotation * 57.2958;
		SetRotation(glm::vec3(0, 0, rotation));
		actorDebug->SetText4("rotX " +std::to_string(rotation));
		this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(dashAnim);
	}
	else
	{
		SetRotation(glm::vec3(0));
	}
	//Imgui Debug
	actorDebug->SetText1(std::to_string(isDashing));
	actorDebug->SetText2(std::to_string(coolDown));
	//actorDebug->SetText3(std::to_string(x) + " " + std::to_string(y));
	actorDebug->SetText3(
		+ "speed "
		+ std::to_string(speed)
		+ " move "
		+ std::to_string(direction.x * speed * dashSpeed));


	// Trigger when collide with something
	std::map<int, Collider*>* collideds = &(this->GetComponent<ComponentPhysics>()->body)
		->GetCollider()->GetCollideds();
	if (SceneSystem::GetInstance()->GetCurrentScene() == mainScene
		&&
		collideds->size() > 0)
	{
		const Vana::Node* stg = collideds->begin()->second->GetOwnerComponent()->GetOwner()->GetParent();
		actorDebug->SetText5(std::to_string(stg->nodeID) + " stage Man Children : " + std::to_string(stg->GetChildren().size()));
		//std::cout << "collideds size : " << collideds->size() << " id : " << collideds->begin()->second->colliderID << std::endl;
		for (auto& c : *collideds)
		{
			// collided with 
			// DiamondHead
			//collideds->erase(c.first);
			Node* n = dynamic_cast<DiamondHead*>(c.second->GetOwnerComponent()->GetOwner());
			if (n)
			{
				if (isDashing)
				{
					//std::cout << " Hit Diamond Head" << std::endl;
					n->Destroy();
					coolDown = 0.3;
					++currentScore;
					scoreBoard->SetScore(currentScore);
					return;
				}
				else
				{
					//state = Actor::DEAD;
					return;
				}
				continue;
			}
			// collided with 
			// DiamondArrow
			n = dynamic_cast<DiamondArrow*>(c.second->GetOwnerComponent()->GetOwner());
			if (n)
			{
				if (isDashing)
				{
					//std::cout << " Hit Diamond Arrow" << std::endl;
					// destroy
					n->Destroy();
					coolDown = 0.3;
					return;
				}
				else
				{
					// Grace Period
					if (false)
					{
						return;
					}
					state = Actor::DEAD;
					return;

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

void Actor::Dampen(double _dt)
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
