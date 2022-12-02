#include "Enemy.h"
#include "actor.h"
#include "global.h"

Enemy::Enemy(Texture* _texture, glm::vec3 _position, glm::vec3 _spriteSize, Animation2D* _idle)
	: Node()
	, texture(_texture)
	, idle(_idle)
{
	ComponentTransform* ct = new ComponentTransform();
	ComponentRenderer* cr = new ComponentRenderer(_texture, _spriteSize);
	ComponentPhysics* cp = new ComponentPhysics(Vana::collisionManager, _spriteSize, 1, 0);
	ComponentAnimator2D* compAnim2D = new ComponentAnimator2D();
	this->AddComponent(ct);
	this->AddComponent(cr);
	this->AddComponent(cp);
	this->AddComponent(compAnim2D);
	body = GetComponent<ComponentPhysics>()->body;
	this->SetPosition(_position);
}

Enemy::~Enemy()
{
}

void Enemy::Init()
{
	this->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(idle);
	this->GetComponent<ComponentAnimator2D>()->Play();
}

void Enemy::Update(double _dt)
{
	// Check if Collide with Player
	// Kill self
	std::map<int, Collider*>* collideds = &(this->GetComponent<ComponentPhysics>()->body)
		->GetCollider()->GetCollideds();
	if (collideds->size() > 0)
	{
		for (auto& collider : *collideds)
		{
			Actor* player = dynamic_cast<Actor*>(collider.second->GetOwnerComponent()->GetOwner());
			if (player)
			{
				CollideWithPlayer();
			}
		}
	}
}

DiamondHead::DiamondHead(glm::vec3 _position)
	: Enemy(texDiamondHead
		, _position
		, diamondHeadSpriteSize
		, diamondHeadIdle)
{

}

DiamondHead::~DiamondHead()
{
	
}

void DiamondHead::Update(double _dt)
{
	Enemy::Update(_dt);
	glm::vec2 spriteAt = GetComponent<ComponentAnimator2D>()->GetAnimator2D()->GetCurrentAnimation()->GetSpriteOffset();
	//std::cout << GetComponent<ComponentAnimator2D>()->GetAnimator2D()->IsPlaying() 
		//<< " sprite At : " << spriteAt.x << ", " << spriteAt.y << std::endl;
	// Ask StageManager to spawn

}

void DiamondHead::CollideWithPlayer()
{
	// Signal player get hit
	// @@ move collision to player logic
	//std::cout << "Diamond Head get hit " << std::endl;
	 //Destroy();
}

DiamondArrow::DiamondArrow(glm::vec3 _position)
	: Enemy(texDiamondArrow
		, _position
		, diamondArrowSpriteSize
		, diamondArrowIdle)
{
}

void DiamondArrow::Update(double _dt)
{
	// seek player
	float speed = 200;
	glm::vec3 direction = player->GetPosition() - this->GetPosition();
	direction = glm::normalize(direction);
	PhysicsBody* body = GetComponent<ComponentPhysics>()->body;

	glm::vec3 velocity = glm::vec3(direction.x * speed, direction.y * speed, 0.0);
	body->SetVelocity(velocity);

	float rotation = atan2(direction.y, direction.x);
	rotation = rotation * 57.2958;
	SetRotation(glm::vec3(0,0,rotation));
}

void DiamondArrow::CollideWithPlayer()
{

}