#include <VanaEngine.h>

#include "actor.h"
#include "ActorDebug.h"

#include "Enemy.h"
#include "StageManager.h"
#include "ScoreSprite.h"

#include "CallBackFunction.h"
#include "InputListener.h"

#include "global.h"



int main()
{
	// Vana Engine Init
	Vana::Init(WINDOW_WIDTH, WINDOW_HEIGHT);
	GraphicSystem::GetInstance()->SetBackgroundColor(glm::vec3(0.6, 0.7, 0.9));
	GraphicSystem::GetInstance()->SetViewScale(glm::vec2(2.0));
	 
	// Init Scene
	introScene = new Scene(nf, "../resources/scenes/intro.json");
	mainScene = new Scene(nf, "../resources/scenes/main.json");
	endScene = new Scene(nf, "../resources/scenes/end.json");

	// Init Texture  
	texPlayer = new Texture("../resources/textures/va-sheet.png");
	texDiamondHead = new Texture("../resources/textures/spriteSheet-test.png");
	texDiamondArrow = new Texture("../resources/textures/diamondArrowIdle.png");
	texScore = new Texture("../resources/textures/number.png");

	// Init Player Debug
	actorDebug = new ActorDebug("ActorDebug", 200, 100);

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

	InputListener* listener = new InputListener(INPUT_KEY_RESET, &StartGame);
	introScene->AddExtendedNode(listener);

	// Set introScene as StartScene
	SceneSystem::GetInstance()->SetStartScene(introScene);

	// Vana Engine Update
	Vana::Update();

	// Terminate Data Allocation
	TerminateGlobalVal();

	return 0;
}

