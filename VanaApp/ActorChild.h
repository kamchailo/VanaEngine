#pragma once
#include <NodeGraphic.h>

class ActorChild : public NodeGraphic
{
public:
	ActorChild(Node* parent, Texture* tex);
	void Init();
	void Update();

};