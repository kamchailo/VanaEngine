#pragma once
#include "pch.h"
#include "framework.h"
#include "Node.h"
#include "NodeGraphic.h"
#include "Graphics.h"
#include "Shader.h"
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
	inline Node* root;
	void Update();
}
