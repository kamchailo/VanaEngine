#pragma once
#include <NodeGraphic.h>

class Actor : public Vana::Node
{
public:
	Actor(Vana::Node* parent, Texture * tex, glm::vec2 spriteSize);
	void Init();
	void Update(double _dt);

};