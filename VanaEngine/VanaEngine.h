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
	inline GraphicSystem* graphicSystem;
	inline GameUI* gameUI;
	inline Node* root;
	inline Logger* logSystem;
	inline CollisionManager collisionManager;
	inline EventManager coreEventManager;
	void Terminate();
}
