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
	root = new Vana::Node();
	return 0;
}

void Vana::Update()
{
	root->DefaultInit();


	// while engine working

	// root->DefaultUpdate();
	// collisionManager.Update();

	// input
	
	// graphic update

	double MS_PER_UPDATE = 1.0 / 60.0;

	double previousTime = glfwGetTime();
	double lag = 0.0;

	int count = 0;
	
	//while (true)
	//{
	//	double currentTime = glfwGetTime();
	//	double elapsedTime = currentTime - previousTime;
	//	previousTime = currentTime;
	//	lag += elapsedTime;

	//	Input::GetInstance()->Update();
	//	count = 0;
	//	while (lag >= MS_PER_UPDATE)
	//	{
	//		//std::cout << "INSIDE SUPER UPDATE" << std::endl;
	//		collisionManager.Update();
	//		root->DefaultUpdate();
	//		++count;
	//		if(count >0)
	//			std::cout << count << " ||| " << lag << std::endl;
	//		lag -= MS_PER_UPDATE;
	//	}

	//	GraphicSystem::GetInstance()->GraphicUpdate();
	//	GraphicSystem::GetInstance()->GraphiceSwapBuffer();
	//}


	//// has to set to wait for dt
	while (!GraphicSystem::GetInstance()->GraphicUpdate())
	{
		Input::GetInstance()->Update();
		// All Graphic Update Goes Here
		root->DefaultUpdate();
		collisionManager.Update();
		GraphicSystem::GetInstance()->GraphiceSwapBuffer();
	}

	Vana::Terminate();
}

void Vana::Terminate()
{
	delete(logSystem);
	delete(root);
}