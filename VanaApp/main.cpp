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

	mainScene = new Scene(nf, "../resources/scenes/test.json");
	endScene = new Scene(nf, "../resources/scenes/test.json");


	texPlayer = new Texture("../resources/textures/spriteSheet-test.jpg");
	texDiamondHead = new Texture("../resources/textures/spriteSheet-test.jpg");


	//Vana::Node* root = SceneSystem::GetInstance()->GetCurrentScene()->GetRoot();

	Actor* b = new Actor(texPlayer, glm::vec2(50, 50));
	mainScene->AddExtendedNode(b);

	diamondHeadIdle = new Animation2D(texDiamondHead, 4, 4, true, true);
	diamondHeadIdle->AddKeyFrame(0, 0);
	diamondHeadIdle->AddKeyFrame(0.5, 1);
	diamondHeadIdle->AddKeyFrame(1, 2);
	diamondHeadIdle->AddKeyFrame(1.5, 3);
	diamondHeadIdle->SetMaxDuration(4.0);
	DiamondHead* d = new DiamondHead(glm::vec3(-100,-100,0));
	mainScene->AddExtendedNode(d);

	// Set mainScene as StartScene
	SceneSystem::GetInstance()->SetStartScene(mainScene);

	// Vana Engine Update
	Vana::Update();

	return 0;
}

