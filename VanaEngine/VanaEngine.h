#pragma once
#include "pch.h"
#include "framework.h"
#include "Node.h"
#include "NodeGraphic.h"
#include "Graphics.h"
#include "Shader.h"
#include "ShaderCollection.h"

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
	int Init();
	inline Node* root;
	void Update();
}
