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
	gameUI = new GameUI(GraphicSystem::GetInstance()->GetWindow());
	Input::GetInstance()->Init();
	ShaderCollection::Init();
	MeshCollection::Init();

	// @@ change to empty scene
	//root = new Vana::Node();
	SceneSystem::GetInstance()->Init();
	return 0;
}

void Vana::Update()
{
	//SceneSystem::GetInstance()->GetCurrentScene()->Init();
	//root->DefaultInit();

	double MS_PER_UPDATE = 1.0 / 60.0;

	double previousTime = glfwGetTime();
	double currentTime = previousTime;
	double deltaTime = 0;
	double lag = 0.0;

	int count = 0;
	
	// Main GameLoop
	while (!GraphicSystem::GetInstance()->GraphicUpdate())
	{
		currentTime = glfwGetTime();
		deltaTime = currentTime - previousTime;
		previousTime = currentTime;
		// @@ Add fixed update
		Input::GetInstance()->Update();
		
		// switch to scene system instead

		SceneSystem::GetInstance()->Update(deltaTime);
		//SceneSystem::GetInstance()->GetCurrentScene()->Update(deltaTime);
		//root->DefaultUpdate(deltaTime);

		gameUI->Update();
		collisionManager.Update();
		GraphicSystem::GetInstance()->GraphiceSwapBuffer();
		coreEventManager.DispatchEvent(SceneSystem::GetInstance()->GetCurrentScene()->GetRoot());

	}
	Vana::Terminate();
}

void Vana::Terminate()
{
	delete(logSystem);
	delete(root);
}