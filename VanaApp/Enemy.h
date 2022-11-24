#pragma once
#include <VanaEngine.h>

/*
* Base Class Enemy
*/
class Enemy : public Vana::Node
{
public:
	Enemy(Texture* _texture, glm::vec3 _position, glm::vec3 _spriteSize, Animation2D* _idle);
	virtual ~Enemy();
	virtual void Init();
	virtual void Update(double _dt);
	virtual void CollideWithPlayer() = 0;
private:
	Texture* texture;
	PhysicsBody* body;
	Animation2D* idle;
	double maxAnimDuration;
};

class DiamondHead : public Enemy
{
public:
	DiamondHead(glm::vec3 _position);
	virtual ~DiamondHead();
	virtual void Update(double _dt);
	virtual void CollideWithPlayer();
private:

};

class DiamondArrow : public Enemy
{

};