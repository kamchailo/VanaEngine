#include "StageManager.h"
#include "Enemy.h"

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
	if (GetChildren().size() >= 40)
	{
		return;
	}
	// spawn diamondHead and more frequent over time
	countingTime += _dt;
	if (countingTime > secondPerSpawn)
	{
		DiamondHead* d = new DiamondHead(RandomPosition());
		d->Init();
		AddChild(d);
		countingTime = 0.0;
	}
	arrowTime += _dt;
	if (arrowTime > arrowSpawnTime)
	{
		for (auto& c : this->GetChildren())
		{
			DiamondArrow* a = new DiamondArrow(c.second->GetPosition());
			a->Init();
			AddChild(a);
			//std::cout << "Spawn at " << a->GetPosition().x << ", " << a->GetPosition().y << std::endl;
		}
		arrowTime = 0.0;
	}
}

glm::vec3 StageManager::RandomPosition()
{
	int x = (((double)std::rand() / RAND_MAX) - 0.5) * levelSize.x;
	int y = (((double)std::rand() / RAND_MAX) - 0.5) * levelSize.y;
	//std::cout << "Spawn at " << x << ", " << y << std::endl;
	return glm::vec3(x, y, 0);;
}

void StageManager::SpawnEnemy(Enemy* e)
{
}