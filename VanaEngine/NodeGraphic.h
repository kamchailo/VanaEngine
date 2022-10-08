#pragma once
#include "pch.h"
#include "Node.h"
#include "Graphics.h"
#include "Shader.h"
#include "ShaderCollection.h"


struct Geometry
{
	// either include vert and mesh or separate//
	float* vertices;
	unsigned int* indices;
};


class NodeGraphic : public Vana::Node
{
public:
	NodeGraphic(Vana::Node* parentNode, float* vertices, unsigned int shaderID);
	NodeGraphic(Vana::Node* parentNode, float* vertices, unsigned int* indices, unsigned int shaderID);
	~NodeGraphic();
	void GenNodeBuffer();
	void Update();
	unsigned int VAO;
	void Draw();
	unsigned int shaderID;
private:
	Geometry* geometry;
	unsigned int VBO, EBO;

};