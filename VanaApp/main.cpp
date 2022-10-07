#include <VanaEngine.h>

float vert1[] =
{
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	 0.0f,  0.5f, 0.0f
};


NodeGraphic* nG = new NodeGraphic(Vana::root, vert1, NULL);

int main()
{
	Vana::Init();

	Vana::Update();


	return 0;
}