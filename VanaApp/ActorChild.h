#pragma once
#include <NodeGraphic.h>

class ActorChild : public NodeGraphic
{
public:
	ActorChild(Node* parent, Texture* tex, glm::vec2 spriteSize);
	void Init();
	void Update();

};