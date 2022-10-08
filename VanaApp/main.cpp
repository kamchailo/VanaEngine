#include <VanaEngine.h>

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
	Vana::Init();
	//NodeGraphic* nG = new NodeGraphic(Vana::root, vert1, sizeof(vert1), SHADER_DEFAULT_ID);
	NodeGraphic* nG = new NodeGraphic(Vana::root, rect, sizeof(rect), indices, sizeof(indices), SHADER_DEFAULT_ID);
	NodeGraphic* tri = new NodeGraphic(nG, vert1, sizeof(vert1), SHADER_DEFAULT_ID);
	nG->Scale(glm::vec3(0.5, 0.5, 1.0));
	//nG->Translate(glm::vec3(0.0, 10.0, 0.0));
	tri->Translate(glm::vec3(400, 0, 0.0));
	Vana::Update();


	return 0;
}