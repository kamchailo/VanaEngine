#pragma once
#include "pch.h"
#include "Graphics/ShaderCollection.h"
#include "Graphics/MeshCollection.h"

namespace Vana
{
	int Init(int _width, int _height);
	void Update();
	void Terminate();
	inline GameUI* gameUI;
	inline Logger* logSystem;
	inline CollisionManager collisionManager;
	inline EventManager coreEventManager;
	//inline SceneSystem* sceneSystem;
	// @@ need to remove root 
	inline Node* root;
}
