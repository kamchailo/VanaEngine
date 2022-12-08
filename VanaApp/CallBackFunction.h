#pragma once

#include <VanaEngine.h>
#include "global.h"
#include "actor.h"
#include "Enemy.h"
#include "StageManager.h"
#include "ScoreSprite.h"

// Function Callback
void ResetGame()
{
	scoreBoard = new ScoreBoard(texScore, scoreFontSize, glm::vec3(25.0, 250.0, 0.0));
	mainScene->AddExtendedNode(scoreBoard);

	// Init Player
	player = new Actor(texPlayer, glm::vec2(50, 50));
	mainScene->AddExtendedNode(player);

	// StageManager
	StageManager* stageManager = new StageManager(glm::vec2(800, 600));
	mainScene->AddExtendedNode(stageManager);

	// Switch Scene
	SceneSystem::GetInstance()->SwitchScene(mainScene);
}