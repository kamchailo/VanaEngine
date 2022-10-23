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
	int Init(int width, int height);
	void Update();
	inline GraphicSystem* graphicSystem;
	inline Node* root;
	inline Logger* logSystem;
	inline CollisionManager collisionManager;
	void Terminate();
}
