#include "pch.h"
#include "Component.h"
#include "Nodes/Node.h"

Vana::Node* Component::GetOwner() const
{
	return owner;
}

void Component::SetOwner(Vana::Node* newOwner)
{
	owner = newOwner;
}