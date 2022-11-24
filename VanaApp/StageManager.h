#pragma once
#include <VanaEngine.h>
#include "Enemy.h"

/*
* Stage Manager control spawning of enemy
*/

class StageManager : public Vana::Node
{
public :
	StageManager();
	virtual void Init();
	virtual void Update(double _dt);
private:
	void SpawnEnemy(Enemy* e);
	std::map<int, Enemy*> allEnemies;
};