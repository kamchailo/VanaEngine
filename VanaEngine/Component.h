#pragma once

#include "pch.h"

class Node;

class Component
{
public:
	Component();
	virtual ~Component();
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Shutdown() = 0;
	virtual void HandleEvent() = 0;
	// setowner
	Node* GetOwner() const;
	void SetOwner(Node* newOwner);
protected:
	// owner
	Node* owner;
};