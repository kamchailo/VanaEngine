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
	void Update(double _dt);
	void Shutdown();
	virtual void HandleEvent(Event* _event);
	void Draw();
	void SetTilling(glm::vec2 _tilling);
	void SetTillingOffset(glm::vec2 _tillingOffset);
private:
	ShapeType type;
	Mesh* mesh;
	Shader* shader;
	Texture* texture;
	glm::vec2 spriteSize;
	glm::vec2 tilling;
	glm::vec2 tillingOffset;
};