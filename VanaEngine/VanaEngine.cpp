// VanaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "VanaEngine.h"


GraphicSystem graphicSystem;
//Vana::Node* root = NULL;

int Vana::Init()
{
	std::cout << "Vana Engine Initializing" << std::endl;
	graphicSystem.Init();
	root = new Vana::Node(NULL);
	return 0;
}

void Vana::Update()
{
	while (!graphicSystem.GraphicUpdate())
	{
		root->Update();

		graphicSystem.GraphiceSwapBuffer();
	}

}