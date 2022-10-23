#pragma once
#include "pch.h"
#include "Node.h"
#include "Graphics.h"
#include "Shader.h"
#include "ShaderCollection.h"
#include "Mesh.h"
#include "Texture.h"

struct Geometry
{
	Mesh mesh;
	// Collider ?

	// about to be deleted
	float* vertices;
	int verticesCount;
	unsigned int* indices;
	int indicesCount;
	// ^^^^^^^^^^^^^^^^^^
};

enum ShapeType 
{
	SHAPE_VERT,
	SHAPE_MESH,
	SHAPE_SPRITE
};

class NodeGraphic : public Vana::Node
{
public:
	NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, ShapeType type, glm::vec2 spriteSize);
	NodeGraphic(Node* parentNode, Mesh* mesh, Shader* shader, Texture* texture, glm::vec2 spriteSize);
	~NodeGraphic();
	void DefaultInit();
	void DefaultUpdate();
	ShapeType type;
	void Draw();
	Shader* shader;
private:
	Mesh* mesh;
	Texture* texture;
	glm::vec2 spriteSize;
};