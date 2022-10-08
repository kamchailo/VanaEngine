#pragma once
#include "Graphics.h"

class Mesh
{
public:
	Mesh(float* vertices, int verticesCount);
	Mesh(float* vertices, int verticesCount, unsigned int* indices, int indicesCount);
	Mesh(float* spriteVertices, int arraySize, unsigned int* indices, int indicesCount, int strideCount, int colorPosition, int texCoordinatePosition);
	~Mesh();
	unsigned int VAO, VBO, EBO;
private:
};