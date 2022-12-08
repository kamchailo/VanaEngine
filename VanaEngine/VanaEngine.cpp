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
	
	// Graphic Init
	GraphicSystem::GetInstance()->Init(width, height);
	ShaderCollection::Init();
	MeshCollection::Init();
	gameUI = new GameUI(GraphicSystem::GetInstance()->GetWindow());
	
	// Input Init
	Input::GetInstance()->Init();

	// Scene Init
	SceneSystem::GetInstance()->Init();

	// Physics Init
	collisionManager.Init();
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
		
		// Delete Dead Node (!isAlive)
		// before physics calculation
		SceneSystem::GetInstance()->GetCurrentScene()->ClearDeadNode();

		// call collision before update
		// so Node Update can response to physics calculation
		// collisionManager clear collideds
		collisionManager.Update();
		SceneSystem::GetInstance()->Update(deltaTime);

		gameUI->Update();

		GraphicSystem::GetInstance()->DrawScene();

		GraphicSystem::GetInstance()->GraphiceSwapBuffer();
		// reduce event
		//coreEventManager.DispatchEvent(SceneSystem::GetInstance()->GetCurrentScene()->GetRoot());

	}
	SceneSystem::GetInstance()->GetCurrentScene()->Unload();
	Vana::Terminate();
}

void Vana::Terminate()
{
	delete(logSystem);
	delete(root);
}