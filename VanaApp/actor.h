#pragma once
#include <NodeGraphic.h>

class Actor : public NodeGraphic
{
public:
	Actor(Node* parent, Texture * tex);
	void Init();
	void Update();

};