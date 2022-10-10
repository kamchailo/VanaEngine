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

	//NodeGraphic* rect1 = new NodeGraphic(Vana::root, rectMesh, SHADER_DEFAULT, SHAPE_MESH);
	//rect1->Scale(glm::vec3(0.7, 1.0, 1.0));
	//rect1->Translate(glm::vec3(-300, 200, 0));
	////rect1->Rotate(glm::vec3(0.0, 0.0, 45));
	////rect1->Rotate(glm::vec3(0.0, 0.0, 40.0));
	//NodeGraphic* rect1_1 = new NodeGraphic(rect1, rectMesh, SHADER_DEFAULT, SHAPE_MESH);
	//rect1_1->Scale(glm::vec3(0.2, 0.2, 1.0));
	//rect1_1->Translate(glm::vec3(0, -200, 0));
	//NodeGraphic* rect1_2 = new NodeGraphic(rect1, rectMesh, SHADER_DEFAULT, SHAPE_MESH);
	//rect1_2->Scale(glm::vec3(0.2, 0.2, 1.0));
	//rect1_2->Translate(glm::vec3(0, -0, 0));
	//NodeGraphic* tri1 = new NodeGraphic(Vana::root, triMesh, SHADER_DEFAULT, SHAPE_VERT);
	//tri1->Scale(glm::vec3(0.7, 1.0, 1.0));
	//tri1->Translate(glm::vec3(300, 200, 0));
	////tri1->Rotate(glm::vec3(0.0, 0.0, -70.0));
	//NodeGraphic* rect2_1 = new NodeGraphic(tri1, rectMesh, SHADER_DEFAULT, SHAPE_MESH);
	//rect2_1->Scale(glm::vec3(0.2, 0.2, 1.0));
	//rect2_1->Translate(glm::vec3(0, 0, 0));
	//NodeGraphic* rect2_2 = new NodeGraphic(tri1, rectMesh, SHADER_DEFAULT, SHAPE_MESH);
	//rect2_2->Scale(glm::vec3(0.2, 0.2, 1.0));
	//rect2_2->Translate(glm::vec3(0, 0, 0));
	//NodeGraphic* spt1 = new NodeGraphic(Vana::root, MESH_SPRITE, SHADER_SPRITE, tex);
	//spt1->Scale(glm::vec3(0.8, 0.2, 1.0));
	//spt1->Translate(glm::vec3(0.0, -400, 0));
	//spt1->Rotate(glm::vec3(0.0, 0.0, 40.0));

	Actor a(Vana::root, tex);

	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


	Vana::Update();


	return 0;
}

