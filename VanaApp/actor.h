#pragma once
#include <VanaEngine.h>

class ActorDebug;

class Actor : public Vana::Node
{
public:
	Actor( Texture * tex, glm::vec2 spriteSize);
	virtual ~Actor() { std::cout << "delete actor" << std::endl; };
	void Init();
	void Update(double _dt);

private:
	Vana::Transform* transf;
	PhysicsBody* bod;
	glm::vec3 direction = glm::vec3(0);
	float speed = 0.0f;
	const float speedStep = 50.0f;
	const float maxSpeed = 300.0f;
	bool isDashing = false;
	float dashSpeed = 1.0f;
	const float dashActive = 15.0f;
	double coolDown = 0.0;
	const double maxCoolDown = 1.5;

	// Animation
	Texture* idleTex;
	Animation2D* idle;
	ActorDebug* actorDebug;
};