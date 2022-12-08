#pragma once
#include <VanaEngine.h>
#include "Enemy.h"

/*
* Stage Manager control spawning of enemy
*/

class StageManager : public Vana::Node
{
public :
	StageManager(glm::vec2 _levelSize);
	virtual void Init();
	virtual void Update(double _dt);
private:
	glm::vec3 RandomPosition();
	void SpawnEnemy(Enemy* e);
	std::map<int, Enemy*> allEnemies;
	float secondPerSpawn = 4.0f;
	float arrowSpawnTime = 3.0f;
	double countingTime = 0.0;
	double arrowTime = 0.0;
	glm::vec2 levelSize;
	// difficulty : 0.0 lowest - 1.0 highest
	float difficulty = 0.0;
};