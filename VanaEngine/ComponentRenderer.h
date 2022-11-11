#pragma once
#include"pch.h"

enum ShapeType
{
	SHAPE_VERT,
	SHAPE_MESH,
	SHAPE_SPRITE
};

class ComponentRenderer : public Component
{
public:
	ComponentRenderer();
	ComponentRenderer(Mesh* mesh, Shader* shader, Texture* texture, glm::vec2 size);
	ComponentRenderer(Texture* texture, glm::vec2 size);
	void Init();
	void Update();
	void Shutdown();
	void HandleEvent();
	void Draw();
private:
	ShapeType type;
	Mesh* mesh;
	Shader* shader;
	Texture* texture;
	glm::vec2 spriteSize;
};