#include <VanaEngine.h>

float vert1[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};



int main()
{
	Vana::Init();
	NodeGraphic* nG = new NodeGraphic(Vana::root, vert1, NULL);

	Vana::Update();


	return 0;
}