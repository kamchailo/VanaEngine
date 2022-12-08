#pragma once
#include <VanaEngine.h>

class Actor : public Vana::Node
{
	enum PlayerState
	{
		ALIVE,
		DEAD
	};
public:
	Actor( Texture * tex, glm::vec2 spriteSize);
	virtual ~Actor() { std::cout << "delete actor" << std::endl; };
	void Init();
	void Update(double _dt);

private:
	void Dampen(double _dt);

	Vana::Transform* transf;
	PhysicsBody* bod;
	glm::vec3 direction = glm::vec3(0);
	float speed = 1.0f;
	const float speedStep = 1200.0f;
	const float maxSpeed = 400.0f;
	bool isDashing = false;
	float dashSpeed = 1.0f;
	const float dashActive = 5.0f;
	const float dashDamped = 3.0f;
	double coolDown = 0.0;
	const double maxCoolDown = 1.5;

	PlayerState state = Actor::ALIVE;

	// Animation
	Texture* idleTex;
	Texture* dashTex;
	Animation2D* idle;
	Animation2D* dashAnim;
};