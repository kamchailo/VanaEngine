#pragma once
#include "pch.h"
#include "ShaderCollection.h"
#include "MeshCollection.h"

//class VanaEngine
//{
//public:
//	int Init();
//	void Update();
//	Vana::Node* root;
//
//
//};

namespace Vana
{
	int Init(int _width, int _height);
	void Update();
	void Terminate();
	//inline GraphicSystem* graphicSystem;
	inline GameUI* gameUI;
	inline Logger* logSystem;
	inline CollisionManager collisionManager;
	inline EventManager coreEventManager;
	//inline SceneSystem* sceneSystem;
	// @@ need to remove root 
	inline Node* root;
}
