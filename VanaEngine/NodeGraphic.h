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
	NodeGraphic(Vana::Node* parentNode, float* vertices, int veticesSize, Shader* shader);
	NodeGraphic(Node* parentNode, float* vertices, int verticesCount, unsigned int* indices, int indicesCount, Shader* shader);
	~NodeGraphic();
	void GenNodeBufferForVert();
	void GenNodeBufferIndices();
	void DefaultInit();
	void DefaultUpdate();
	ShapeType type;
	unsigned int VAO;
	void Draw();
	Shader* shader;
private:
	Geometry* geometry;
	unsigned int VBO, EBO;

};