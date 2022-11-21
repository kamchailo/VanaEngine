#include <VanaEngine.h>

#include "actor.h"
#include "ActorChild.h"

int main()
{
	// Vana Engine Init
	Vana::Init(800, 600);


	NodeFactory nf;
	Vana::Node impScene = nf.CreateScene("../resources/scenes/test.json");
	delete Vana::root;
	Vana::root = &impScene;


	Texture* tex = new Texture("../resources/textures/spriteSheet-test.jpg");
	Actor* b = new Actor(Vana::root, tex, glm::vec2(200, 50));


	Animation2D* idle = new Animation2D(tex, 4, 4, true, true);
	idle->AddKeyFrame(0, 0);
	idle->AddKeyFrame(1, 1);
	idle->AddKeyFrame(1, 1);
	idle->AddKeyFrame(2, 2);
	idle->AddKeyFrame(3, 3);
	idle->AddKeyFrame(4, 4);
	idle->AddKeyFrame(5, 5);
	idle->AddKeyFrame(6, 6);
	idle->AddKeyFrame(7, 7);
	idle->AddKeyFrame(8, 8);
	idle->AddKeyFrame(9, 9);
	idle->AddKeyFrame(10, 10);
	idle->AddKeyFrame(11, 11);
	idle->AddKeyFrame(12, 12);
	idle->AddKeyFrame(13, 13);
	idle->AddKeyFrame(14, 14);
	idle->AddKeyFrame(15, 15);

	idle->SetMaxDuration(16.0);

	ComponentAnimator2D* compAnim2D = new ComponentAnimator2D();
	//compAnim2D->SetPlayingAnimation(idle);
	
	//compAnim2D->SetPlayingAnimation(idle->GetID());
	b->AddComponent(compAnim2D);
	b->GetComponent<ComponentAnimator2D>()->SetPlayingAnimation(idle);
	//compAnim2D->AddFrame(1, 1);
	//compAnim2D->AddFrame(2, 2);
	//compAnim2D->AddFrame(3, 3);
	//compAnim2D->AddFrame(4, 4);
	//compAnim2D->AddFrame(5, 5);
	//compAnim2D->AddFrame(6, 6);
	//compAnim2D->AddFrame(7, 7);
	//compAnim2D->AddFrame(8, 8);
	//compAnim2D->AddFrame(9, 9);
	//compAnim2D->AddFrame(10, 10);
	//compAnim2D->AddFrame(11, 11);
	//compAnim2D->AddFrame(12, 12);
	//compAnim2D->AddFrame(13, 13);
	//compAnim2D->AddFrame(14, 14);
	//compAnim2D->AddFrame(15, 15);
	//compAnim2D->AddFrame(3.0, 3);kp
	//compAnim2D->SetMaxDuration(16.0);
	// Vana Engine Update
	Vana::Update();

	return 0;
}

