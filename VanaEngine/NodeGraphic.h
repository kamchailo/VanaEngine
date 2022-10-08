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
	int verticesCount;
	unsigned int* indices;
	int indicesCount;
};

enum ShapeType 
{
	SHAPE_VERT,
	SHAPE_MESH
};

class NodeGraphic : public Vana::Node
{
public:
	NodeGraphic(Vana::Node* parentNode, float* vertices, int veticesSize, unsigned int shaderID);
	NodeGraphic(Node* parentNode, float* vertices, int verticesCount, unsigned int* indices, int indicesCount, unsigned int shaderID);
	~NodeGraphic();
	void GenNodeBufferForVert();
	void GenNodeBufferIndices();
	void Update();
	ShapeType type;
	unsigned int VAO;
	void Draw();
	unsigned int shaderID;
private:
	Geometry* geometry;
	unsigned int VBO, EBO;

};