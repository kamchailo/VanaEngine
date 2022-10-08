// VanaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "VanaEngine.h"


GraphicSystem graphicSystem;
//Vana::Node* root = NULL;

int Vana::Init(int width, int height)
{
	std::cout << "Vana Engine Initializing" << std::endl;
	graphicSystem.Init(width, height);
	ShaderCollection::Init();
	root = new Vana::Node(NULL);
	root->DefaultInit();
	return 0;
}

void Vana::Update()
{
	while (!graphicSystem.GraphicUpdate())
	{
		// All Graphic Update Goes Here
		root->DefaultUpdate();

		graphicSystem.GraphiceSwapBuffer();
	}

}