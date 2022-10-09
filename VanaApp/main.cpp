#include <VanaEngine.h>

float vert1[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.8f, 0.0f
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

	NodeGraphic* ng1 = new NodeGraphic(Vana::root, triMesh, SHADER_DEFAULT, SHAPE_VERT);
	NodeGraphic* spt1 = new NodeGraphic(ng1, rectMesh, SHADER_DEFAULT, SHAPE_MESH);



	Vana::Update();


	return 0;
}