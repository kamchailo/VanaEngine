// VanaEngine.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include "VanaEngine.h"


//GraphicSystem* graphicSystem;
//Vana::Node* root = NULL;

int Vana::Init(int width, int height)
{
	logSystem = new Logger("Engine");
	logSystem->Log(LOG_INFO, "Vana Engine Initializing");
	//graphicSystem = GraphicSystem::GetInstance();
	GraphicSystem::GetInstance()->Init(width, height);
	Input::GetInstance()->Init();
	ShaderCollection::Init();
	MeshCollection::Init();
	root = new Vana::Node(NULL);
	return 0;
}

void Vana::Update()
{
	root->DefaultInit();
	while (!GraphicSystem::GetInstance()->GraphicUpdate())
	{
		// All Graphic Update Goes Here
		root->DefaultUpdate();

		GraphicSystem::GetInstance()->GraphiceSwapBuffer();
	}

}

void Vana::Terminate()
{
	delete(logSystem);
	delete(root);
}