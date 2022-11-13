#include <VanaEngine.h>

#include "actor.h"
#include "ActorChild.h"

int main()
{
	// Vana Engine Init
	Vana::Init(800, 600);


	NodeFactory nf;
	Vana::Node impScene = nf.CreateScene("../resources/scenes/test.json");
	Vana::root = &impScene;


	Texture* tex = new Texture("../resources/textures/sharkey.jpg");
	Actor* b = new Actor(Vana::root, tex, glm::vec2(200, 50));

	// Vana Engine Update
	Vana::Update();

	return 0;
}

