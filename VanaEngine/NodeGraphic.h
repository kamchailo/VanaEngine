#pragma once
#include "pch.h"
#include "Node.h"
#include "Graphics.h"


struct Geometry
{
	// either include vert and mesh or separate//
	float* vertices;
	float* indices;
};


class NodeGraphic : public Vana::Node
{
public:
	NodeGraphic(Vana::Node* parentNode, float* vertices, const Shader* shader);
	~NodeGraphic();
	void GenNodeBuffer();
	void Update();
	unsigned int VAO;
	void Draw();
	const Shader* shader;
private:
	Geometry* geometry;
	unsigned int VBO, EBO;

};