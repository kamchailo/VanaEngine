#pragma once

#include "../Nodes/Node.h"

class Component
{
public:
	virtual ~Component() {};
	virtual void Init() = 0;
	virtual void Update(double _dt) = 0;
	virtual void Shutdown() = 0;
	virtual void HandleEvent(Event* _event) = 0;
	Vana::Node* GetOwner() const;
	void SetOwner(Vana::Node* newOwner);
protected:
	Vana::Node* owner;
};