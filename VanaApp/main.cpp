#include <VanaEngine.h>

#include "actor.h"

float vert1[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};


float rect[] =
{
	 0.5f,  0.5f, 0.0f,  // 0 - top right
	 0.5f, -0.5f, 0.0f,  // 1 - bottom right
	-0.5f, -0.5f, 0.0f,  // 2 - bottom left
	-0.5f,  0.5f, 0.0f   // 3 - top left 
};

unsigned int indices[] = {  // note that we start from 0!
	0, 1, 3,   // first triangle
	1, 2, 3    // second triangle
};




int main()
{
	Vana::Init(800, 600);


	Mesh* triMesh = new Mesh(vert1, sizeof(vert1));
	Mesh* rectMesh = new Mesh(rect, sizeof(rect), indices, sizeof(indices));

	Texture* tex = new Texture("../resources/textures/sharkey.jpg");


	Actor a(Vana::root, tex);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	Vana::Update();


	return 0;
}

