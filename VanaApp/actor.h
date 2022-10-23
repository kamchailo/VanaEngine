#pragma once
#include <NodeGraphic.h>

class Actor : public NodeGraphic
{
public:
	Actor(Node* parent, Texture * tex, glm::vec2 spriteSize);
	void Init();
	void Update();

};