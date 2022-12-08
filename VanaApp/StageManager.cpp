#include "StageManager.h"
#include "Enemy.h"
#include "global.h"

#include <random>

StageManager::StageManager(glm::vec2 _levelSize)
{
	levelSize = _levelSize;
}

void StageManager::Init()
{
	secondPerSpawn = 5.0f;
	countingTime = 0.0;
	arrowSpawnTime = 3.0f;
	arrowTime = 0.0;
}

void StageManager::Update(double _dt)
{
	if (GetChildren().size() >= 500)
	{
		//std::cout << "Hit Enemy count Limit" << std::endl;
		return;
	}
	// spawn diamondHead and more frequent over time
	countingTime += _dt;
	// Adjust difficulty Highest in 30 second
	difficulty += _dt / 300.0;
	difficulty = max(0.5, difficulty);
	if (countingTime > secondPerSpawn * (1.0 - difficulty))
	{
		DiamondHead* d = new DiamondHead(RandomPosition());
		d->Init();
		AddChild(d);
		countingTime = 0.0;
	}
	arrowTime += _dt;
	if (arrowTime > arrowSpawnTime)
	{
		// Can not spawn to every children spawn to only Diamond Head
		for (auto &c : this->GetChildren())
		{
			DiamondHead* diamondHead = dynamic_cast<DiamondHead*>(c.second);
			if (diamondHead)
			{
	;			DiamondArrow* a = new DiamondArrow(diamondHead->GetPosition());
				a->Init();
				AddChild(a);
			}
			//std::cout << "Spawn at " << a->GetPosition().x << ", " << a->GetPosition().y << std::endl;
		}
		arrowTime = 0.0;
	}
}

glm::vec3 StageManager::RandomPosition()
{
	std::srand(std::time(nullptr) * 3141592);
	int x = (((double)std::rand() / RAND_MAX) - 0.5) * levelSize.x;
	int y = (((double)std::rand() / RAND_MAX) - 0.5) * levelSize.y;
	//std::cout << std::time(nullptr) << "Spawn at " << x << ", " << y << std::endl;
	return glm::vec3(x, y, 0);;
}

void StageManager::SpawnEnemy(Enemy* e)
{
}