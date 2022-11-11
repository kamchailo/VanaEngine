#pragma once

#include "pch.h"

class Component
{
public:
	//Component();
	virtual ~Component() {};
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;
	virtual void HandleEvent() = 0;
	// setowner
	Vana::Node* GetOwner() const;
	void SetOwner(Vana::Node* newOwner);
protected:
	// owner
	Vana::Node* owner;
};