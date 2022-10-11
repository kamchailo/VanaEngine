#pragma once
#include "pch.h"
#include "framework.h"
#include "Logger.h"
#include "Graphics.h"
#include "Input.h"
#include "Node.h"
#include "NodeGraphic.h"
#include "Shader.h"
#include "ShaderCollection.h"
#include "Mesh.h"
#include "MeshCollection.h"
#include "Texture.h"

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
	void Terminate();
}
