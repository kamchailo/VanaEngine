#include <VanaEngine.h>

#include "actor.h"
#include "ActorChild.h"

#include "Enemy.h"
#include "StageManager.h"

#include "global.h"


int main()
{
	// Vana Engine Init
	Vana::Init(800, 600);

	// Init Scene
	mainScene = new Scene(nf, "../resources/scenes/test.json");
	endScene = new Scene(nf, "../resources/scenes/test.json");

	// Init Texture
	texPlayer = new Texture("../resources/textures/spriteSheet-test.jpg", FALSE);
	texDiamondHead = new Texture("../resources/textures/spriteSheet-test.jpg", FALSE);
	texDiamondArrow = new Texture("../resources/textures/diamondArrowIdle.png", TRUE);

	// Init Player
	player = new Actor(texPlayer, glm::vec2(50, 50));
	mainScene->AddExtendedNode(player);

	// DiamondHead Animation
	diamondHeadIdle = new Animation2D(texDiamondHead, 4, 4, true, true);
	diamondHeadIdle->AddKeyFrame(0, 0);
	diamondHeadIdle->AddKeyFrame(0.5, 1);
	diamondHeadIdle->AddKeyFrame(1, 2);
	diamondHeadIdle->AddKeyFrame(1.5, 3);
	diamondHeadIdle->SetMaxDuration(2.0);

	// DiamondArrow Animation
	diamondArrowIdle = new Animation2D(texDiamondArrow, 3, 1, true, true);
	diamondArrowIdle->AddKeyFrame(0, 0);
	diamondArrowIdle->AddKeyFrame(0.16, 0);
	diamondArrowIdle->AddKeyFrame(0.32, 0);
	diamondArrowIdle->SetMaxDuration(0.48);


	//DiamondHead* d = new DiamondHead(glm::vec3(-100,-100,0));
	//mainScene->AddExtendedNode(d);

	StageManager* stageManager = new StageManager(glm::vec2(800, 600));
	mainScene->AddExtendedNode(stageManager);

	// Set mainScene as StartScene
	SceneSystem::GetInstance()->SetStartScene(mainScene);

	// Vana Engine Update
	Vana::Update();

	return 0;
}

