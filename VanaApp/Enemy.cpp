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
	ComponentPhysics* cp = new ComponentPhysics(Vana::collisionManager, _spriteSize);
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
	std::vector<Collider*> collideds = this->GetComponent<ComponentPhysics>()->body
		->GetCollider()->GetCollideds();
	if (collideds.size() > 0)
	{
		for (auto& collider : collideds)
		{
			Actor* player = dynamic_cast<Actor*>(collider->GetOwnerComponent()->GetOwner());
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